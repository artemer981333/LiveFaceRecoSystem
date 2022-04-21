#include "devicesmanager.h"
#include <thread>

using namespace std;

DevicesManager::DevicesManager(QObject *parent) : QObject(parent)
{

}

const QList<DevicesManager::Rele> &DevicesManager::getReles() const
{
	return reles;
}

void DevicesManager::updateDevices(const QList<DevicesManager::Rele> &reles)
{
	this->reles = reles;
}

void DevicesManager::activateRele(QUuid id)
{
	auto rele = find_if(reles.begin(), reles.end(), [&](const Rele &rele) { return rele.id == id; });
	QString query = rele->query;
	if (rele != reles.end())
	{
		std::thread([query]() { std::system(query.toStdString().c_str()); }).detach();
	}
}

DevicesManager::Rele::Rele(QString name, QString query) : name(name), query(query)
{
	id = QUuid::createUuid();
}

DevicesManager::Rele::Rele(QString name, QString query, QUuid id) : name(name), query(query), id(id)
{

}
