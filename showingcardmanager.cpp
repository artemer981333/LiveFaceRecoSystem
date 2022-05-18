#include "showingcardmanager.h"
#include <iostream>
#include <thread>

using namespace std;

ShowingCardManager::ShowingCardManager(QObject *parent): QObject(parent)
{
	showingCardsNumber = 5;
	enteredNumber = 0;
	exitedNumber = 0;
	secondsSameCards = 5;
}

void ShowingCardManager::setShowingCardsNumber(int number)
{
	if (number <= 0)
		return;
	showingCardsNumber = number;
}

void ShowingCardManager::connectDevicesManager(DevicesManager *manager)
{
	devicesManager = manager;
}

void ShowingCardManager::connectPersonalCardManager(PersonalCardManager *manager)
{
	cardManager = manager;
}

int ShowingCardManager::cardsNumber() const
{
	return cards.size();
}

int ShowingCardManager::entered() const
{
	return enteredNumber;
}

int ShowingCardManager::exited() const
{
	return exitedNumber;
}

ShowingCardManager::DetectionResult ShowingCardManager::personDetected(QUuid id, QString fullName, QString filename, int idCam, bool enterance, QUuid releID, bool fakeFace)
{
	ShowingCard card;
	card.camId = idCam;
	card.enterance = enterance;
	card.filename = filename;
	card.fullName = fullName;
	card.date = QDate::currentDate();
	card.lastDetectedTime = card.time = QTime::currentTime();

	auto personalVisits = find_if(personalsVisits.begin(), personalsVisits.end(), [&](const PersonalVisits &pv) { return pv.cardID == id; });
	bool inVisitsHistory = personalVisits != personalsVisits.end();

	auto firstCardOfCam = find_if(cards.begin(), cards.end(), [&](const ShowingCard &card) { return card.camId == idCam; });
	bool tryedPassRecently = false;
	if (firstCardOfCam != cards.end())
		if (card == *firstCardOfCam && firstCardOfCam->lastDetectedTime.secsTo(card.time) <= secondsSameCards)
			tryedPassRecently = true;

	auto reles = devicesManager->getReles();
	auto rele = find_if(reles.begin(), reles.end(), [&](const DevicesManager::Rele &r) { return releID == r.id; });
	auto pass = [&](bool opening, bool newCard, PassingStatus stat, DetectionResult res)
	{
		if (opening)
		{
			(card.enterance) ? (enteredNumber++) : (exitedNumber++);
			if (personalVisits == personalsVisits.end())
			{
				personalsVisits.append(PersonalVisits(id));
				personalVisits = personalsVisits.end() - 1;
			}
			personalVisits->visits.append(Visit(enterance));
			if (rele != reles.end())
			{
				devicesManager->activateRele(rele->id);
				PassingEvent pe;
				pe.id = id;
				pe.enterance = enterance;
				pe.passed = true;
				pe.time = QDateTime::currentDateTime();
				cout << "SCM emiting !!!!!!!!!!!!!!!!!" << endl;
				emit newPassingEvent(pe);
			}
		}
		if (newCard)
		{
			card.status = stat;
			card.image = QPixmap("./img/" + card.filename);
			cards.push_front(card);
			if (cards.size() > showingCardsNumber)
				cards.pop_back();
		}
		else if (tryedPassRecently)
			firstCardOfCam->status = stat;
		return res;
	};

	auto zoneCheck = [&]()
	{
		if (!inVisitsHistory)
			if (enterance)
				return pass(true, !tryedPassRecently, PassingStatus::Passed, (enterance) ? (DetectionResult::Entered) : (DetectionResult::Exited));
			else
				return pass(false, !tryedPassRecently, PassingStatus::ZoneViolation, DetectionResult::Reexiting);
		else
			if (personalVisits->visits.last().entered == enterance)
				return pass(false, !tryedPassRecently, PassingStatus::ZoneViolation, (enterance) ? (DetectionResult::Reentering) : (DetectionResult::Reexiting));
			else
				return pass(true, !tryedPassRecently, PassingStatus::Passed, (enterance) ? (DetectionResult::Entered) : (DetectionResult::Exited));
	};

	if (fakeFace)
	{
		if (tryedPassRecently)
			return DetectionResult::FakeFace;
		else
			return pass(false, !tryedPassRecently, PassingStatus::Fake, DetectionResult::FakeFace);
	}

	if (tryedPassRecently)
	{
		firstCardOfCam->lastDetectedTime = card.time;
		switch (firstCardOfCam->status)
		{
		case PassingStatus::ZoneViolation:
		{
			return pass(false, false, PassingStatus::ZoneViolation, (enterance) ? (DetectionResult::Reentering) : (DetectionResult::Reexiting));
			break;
		}
		case PassingStatus::Fake:
		{
			if (fakeFace)
				return pass(false, false, PassingStatus::Fake, DetectionResult::FakeFace);
			return zoneCheck();
			break;
		}
		}
		return (enterance) ? (DetectionResult::Entered) : (DetectionResult::Exited);
	}

	return zoneCheck();
}

ShowingCardManager::ShowingCard ShowingCardManager::getCardOnPosition(int position)
{
	if (position >= cards.size() || position < 0)
		throw "out of range";
	if (position < 0)
		return cards[0];
	return cards[position];
}

QString ShowingCardManager::ShowingCard::fio()
{
	return fullName;
}

QString ShowingCardManager::ShowingCard::dt()
{
	QString ret = "";
	ret += date.toString("dd.MM.yyyy") + " ";
	ret += time.toString("hh.mm.ss");
	switch (status)
	{
		case PassingStatus::Passed:
			ret += " OK";
			break;
		case PassingStatus::ZoneViolation:
			ret += " ЗОН";
			break;
		case PassingStatus::Fake:
			ret += " СПУФ";
			break;
	}
	return ret;
}

QString ShowingCardManager::ShowingCard::cam()
{
	QString ret = "";
	ret += QString::number(camId) + " ";
	ret += QString::fromStdString((enterance) ? ("Вход") : ("Выход"));
	return ret;
}

bool ShowingCardManager::ShowingCard::operator ==(const ShowingCardManager::ShowingCard &card)
{
	return fullName == card.fullName && camId == card.camId;
}

ShowingCardManager::PersonalVisits::PersonalVisits(QUuid id) : cardID(id) {}

ShowingCardManager::Visit::Visit() {}

ShowingCardManager::Visit::Visit(bool entered) : entered(entered) { dateTime = QDateTime::currentDateTime(); }

ShowingCardManager::Visit::Visit(QDateTime dateTime, bool entered) : dateTime(dateTime), entered(entered) {}
