#ifndef DEVICESMANAGER_H
#define DEVICESMANAGER_H

#include <QObject>
#include <QList>
#include <QUuid>

class DevicesManager : public QObject
{
	Q_OBJECT


public:
	struct Rele
	{
		Rele(QString name, QString query);
		Rele(QString name, QString query, QUuid id);

		void sendQuery();

		QString name, query;
		QUuid id;
	};


	explicit DevicesManager(QObject *parent = nullptr);

	const QList<Rele> &getReles() const;

	void updateDevices(const QList<Rele> &reles);

signals:

public slots:
	void activateRele(QUuid id);

private:
	QList<Rele> reles;
};

#endif // DEVICESMANAGER_H
