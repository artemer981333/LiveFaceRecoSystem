#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include <QProcess>
#include <thread>
#include "authorisationform.h"

//проверка лицензии
bool checkLicense(QDate &date)
{
	QProcess proc;
	proc.start("ifconfig -a");
	proc.waitForFinished();
	QString str = QString(proc.readAllStandardOutput());
	proc.close();
	int pos = str.indexOf("ether", str.indexOf("eth0"));
	QString MACaddr = QString::fromStdString(str.toStdString().substr(pos + 6, 17));

	QFile licenseFile("license.lfr");
	if (!licenseFile.exists())
	{
		QMessageBox::information(nullptr, "Not license file", "Not license file (license.lfr)");
		std::cout << "Not license file (license.lfr)" << std::endl;
		return false;
	}
	licenseFile.open(QFile::ReadOnly);
	QByteArray bytes = licenseFile.readAll();
	QString readMAC = QString::fromStdString(QString(bytes).toStdString().substr(0, 17));
	if (MACaddr != readMAC)
	{
		QMessageBox::information(nullptr, "Not correct MAC", "Not correct MAC");
		std::cout << "Not correct MAC" << std::endl;
		return false;
	}
	QString readUUID = QString::fromStdString(QString(bytes).toStdString().substr(17, 20));
	if (readUUID != "uhbygvrkismanudyeozz")
	{
		QMessageBox::information(nullptr, "Not correct UUID", "Not correct UUID");
		std::cout << "Not correct UUID" << std::endl;
		return false;
	}
	QString s = QString::fromStdString(QString(bytes).toStdString().substr(37, 10));
	QDateTime readTIME = QDateTime::fromString(s, "dd.MM.yyyy");
	date = readTIME.date();
	if (readTIME.secsTo(QDateTime::currentDateTime()) >= 0)
	{
		QMessageBox::information(nullptr, "License time is gone", "License time is gone");
		std::cout << "License time is gone" << std::endl;
		return false;
	}
	return true;
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QDate date;

	if (!checkLicense(date))
		return 10;

	//постоянная проверка лицензии
	std::thread checkLicenseThread = std::thread([&]()
	{
		while(true)
		{
			std::this_thread::sleep_for(std::chrono::seconds(10));
			if (!checkLicense(date))
			{
				a.exit();
				return 10;
			}
		}
	});
	checkLicenseThread.detach();

	//подключение стилей
	QFile style("Mixchat.qss");
	style.open(QFile::ReadOnly);
	a.setStyleSheet(style.readAll());
	style.close();

	AuthorisationForm authForm;

    MainWindow w;
	QApplication::connect(&authForm, &AuthorisationForm::authorised, &w, &MainWindow::onAuthorised);
	authForm.authorisation();
	w.setLicenseDate(date);
	//w.show();

    return a.exec();
}
