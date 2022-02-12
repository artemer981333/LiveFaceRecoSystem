#ifndef PERSONALCARDMANAGER_H
#define PERSONALCARDMANAGER_H
#include "messagehandler.h"

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QFile>
#include <QUuid>

struct PersonalCard
{
	QUuid id;
	QString imagePath;
	QString name, surname, lastname;
	QString post, subdivision;
};

class PersonalCardManager : public QObject
{
	Q_OBJECT

	QList<PersonalCard> cards;

public:
	explicit PersonalCardManager(QObject *parent = nullptr);

	const QList<PersonalCard> *personalCards() const;


signals:

public slots:

	void addCard(const PersonalCard &card);
	void loadCards(const QString &filename);
	void saveCards(const QString &filename);

};

#endif // PERSONALCARDMANAGER_H
