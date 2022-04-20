#ifndef CARDLAYOUTMANAGER_H
#define CARDLAYOUTMANAGER_H

#include <QDate>
#include <QTime>
#include <QQueue>
#include <QPixmap>
#include "devicesmanager.h"
#include "personalcardmanager.h"

//классс менеджера отображающихся карт (получает идентифицированного человека и решает, добавить его в список пришедших или нет)
class ShowingCardManager
{

	int showingCardsNumber;
	int enteredNumber;
	int exitedNumber;
	double secondsSameCards;

	DevicesManager *devicesManager;
	PersonalCardManager *cardManager;


public:

	enum class DetectionResult
	{
		Entered,
		Exited,
		Reexiting,
		Reentering,
		FakeFace
	};

	enum class PassingStatus
	{
		Passed,
		ZoneViolation,
		Fake,
	};

	struct ShowingCard
	{
		QString fio();
		QString dt();
		QString cam();

		bool operator ==(const ShowingCard &card);
		QString filename;
		QString fullName;
		QDate date;
		QTime time;
		int camId;
		bool enterance;
		QTime lastDetectedTime;
		QPixmap image;
		PassingStatus status;
	};

	struct Visit
	{
		Visit();
		Visit(bool entered);
		Visit(QDateTime dateTime, bool entered);
		QDateTime dateTime;
		bool entered;
	};

	struct PersonalVisits
	{
		PersonalVisits(QUuid id);
		QUuid cardID;
		QList<Visit> visits;
	};

	ShowingCardManager();

	void setShowingCardsNumber(int number);

	void connectDevicesManager(DevicesManager *manager);
	void connectPersonalCardManager(PersonalCardManager *manager);

	int cardsNumber() const;
	int entered() const;
	int exited() const;

	DetectionResult personDetected(QUuid id, QString fullName, QString filename, int idCam, bool enterance, QUuid releID, bool fakeFace);

	ShowingCard getCardOnPosition(int position);

private:

	QQueue<ShowingCard> cards;
	QList<PersonalVisits> personalsVisits;
};

#endif // CARDLAYOUTMANAGER_H
