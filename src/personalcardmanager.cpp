#include "personalcardmanager.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <iostream>

PersonalCardManager::PersonalCardManager(QObject *parent) : QObject(parent)
{

}

const QList<PersonalCard> *PersonalCardManager::personalCards() const
{
	return &cards;
}

void PersonalCardManager::addCard(const PersonalCard &card)
{
	PersonalCard nCard = card;
	nCard.id = QUuid::createUuid();
	cards.append(std::move(card));
}

void PersonalCardManager::editCard(QUuid cardID, const PersonalCard &card)
{
	auto it = std::find_if(cards.begin(), cards.end(), [&](const PersonalCard &card){ return card.id == cardID; });
	if (it == cards.end())
		return;
	*it = card;
	it->id = cardID;
}

void PersonalCardManager::deleteCard(int cardIndex)
{
	if (cards.size() <= cardIndex)
		return;
	cards.erase(cards.begin() + cardIndex);
}

void PersonalCardManager::deleteCard(QUuid cardID)
{
	auto it = std::find_if(cards.begin(), cards.end(), [&](const PersonalCard &card){ return card.id == cardID; });
	if (it == cards.end())
		return;
	cards.erase(it);
}

void PersonalCardManager::loadCards(const QString &filename)
{
	cards.clear();

	PersonalCard card;

	QFile file(filename);
	file.open(QIODevice::ReadOnly);
	if (!file.isOpen())
		return;
	QByteArray bArr = file.readAll();
	file.close();
	QJsonDocument doc = QJsonDocument::fromJson(bArr);

	QJsonArray arr = doc.array();
	QJsonObject obj;
	for (int i = 0; i < arr.size(); ++i)
	{
		obj = arr[i].toObject();
		card.id = obj.take("id").toString();
		card.imagePath = obj.take("imagePath").toString();
		card.name = obj.take("name").toString();
		card.surname = obj.take("surname").toString();
		card.lastname = obj.take("lastname").toString();
		card.post = obj.take("post").toString();
		card.subdivision = obj.take("subdivision").toString();
		card.brightnessCorrection = obj.take("brightness").toInt();
		card.contrastCorrection = obj.take("contrast").toInt();
		cards.append(card);
	}
}

void PersonalCardManager::saveCards(const QString &filename)
{
	QJsonDocument doc;
	QJsonObject obj;
	QJsonArray arr;
	for (int i = 0; i < cards.size(); ++i)
	{
		obj.insert("id", cards[i].id.toString());
		obj.insert("imagePath", cards[i].imagePath);
		obj.insert("name", cards[i].name);
		obj.insert("surname", cards[i].surname);
		obj.insert("lastname", cards[i].lastname);
		obj.insert("post", cards[i].post);
		obj.insert("subdivision", cards[i].subdivision);
		obj.insert("brightness", cards[i].brightnessCorrection);
		obj.insert("contrast", cards[i].contrastCorrection);
		arr.append(obj);
	}
	doc.setArray(arr);

	QByteArray barr = doc.toJson();

	QFile file(filename);
	file.open(QIODevice::WriteOnly);
	file.write(barr);
	file.close();
}

void PersonalCardManager::updateCards(const QList<PersonalCard> &newCards)
{
	cards.clear();
	cards.append(newCards);
}
