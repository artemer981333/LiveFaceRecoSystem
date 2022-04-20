#ifndef DEVICESMANAGER_H
#define DEVICESMANAGER_H

#include <QObject>

class DevicesManager : public QObject
{
	Q_OBJECT
public:
	explicit DevicesManager(QObject *parent = nullptr);

signals:

public slots:
};

#endif // DEVICESMANAGER_H