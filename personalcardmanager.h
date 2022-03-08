#ifndef PERSONALCARDMANAGER_H
#define PERSONALCARDMANAGER_H
#include "messagehandler.h"

#include <QObject>
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

	void addCard(const PersonalCard &card);
	void editCard(QUuid cardID, const PersonalCard &card);
	void deleteCard(int cardIndex);
	void deleteCard(QUuid cardID);
	void loadCards(const QString &filename);
	void saveCards(const QString &filename);

	void updateCards(const QList<PersonalCard> &newCards);

signals:

public slots:


};

#endif // PERSONALCARDMANAGER_H
