#include "personalcardmanager.h"
#include <fstream>

PersonalCardManager::PersonalCardManager(QObject *parent) : QObject(parent)
{

}

const QList<PersonalCard> *PersonalCardManager::personalCards() const
{
	return &cards;
}

void PersonalCardManager::addCard(const PersonalCard &card)
{
	cards.append(card);
}

void PersonalCardManager::loadCards(const QString &filename)
{
	PersonalCard card;

	QFile file(filename);
	file.open(QIODevice::ReadOnly);
	QByteArray arr = file.readAll();
	file.close();
	QJsonDocument doc = QJsonDocument::fromJson(arr);
	QJsonObject obj = doc.object();
	card.imagePath = obj.take("imagePath").toString();
	card.name = obj.take("name").toString();
	card.surname = obj.take("surname").toString();
	card.lastname = obj.take("lastname").toString();
	card.post = obj.take("post").toString();
	card.subdivision = obj.take("subdivision").toString();
	cards.append(card);
}

void PersonalCardManager::saveCards(const QString &filename)
{
	PersonalCard card = cards.back();
	QJsonObject obj;
	obj.insert("imagePath", card.imagePath);
	obj.insert("name", card.name);
	obj.insert("surname", card.surname);
	obj.insert("lastname", card.lastname);
	obj.insert("post", card.post);
	obj.insert("subdivision", card.subdivision);
	QJsonDocument doc;
	doc.setObject(obj);
	QByteArray arr = doc.toJson();

	QFile file(filename);
	file.open(QIODevice::WriteOnly);
	file.write(arr);
	file.close();
}
