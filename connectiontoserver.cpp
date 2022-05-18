#include "connectiontoserver.h"
#include <fstream>

using namespace std;

namespace http = boost::beast::http;

string personalCardToJSON(const PersonalCard &card)
{
	QJsonDocument doc;
	QJsonObject obj;
	obj.insert("id", card.id.toString());
	obj.insert("imagePath", card.imagePath);
	obj.insert("lastname", card.lastname);
	obj.insert("name", card.name);
	obj.insert("post", card.post);
	obj.insert("subdivision", card.subdivision);
	obj.insert("surname", card.surname);
	obj.insert("brightness", card.brightnessCorrection);
	obj.insert("contrast", card.contrastCorrection);
	doc.setObject(obj);

	return doc.toJson().toStdString();
}

PersonalCard personalCardFromJSON(const string &str)
{
	PersonalCard card;
	QByteArray b(str.data());
	QJsonDocument doc = QJsonDocument::fromJson(b);
	QJsonObject obj = doc.object();
	card.id = QUuid(obj.take("id").toString());
	card.imagePath = obj.take("imagepath").toString();
	card.lastname = obj.take("lastname").toString();
	card.name = obj.take("name").toString();
	card.post = obj.take("post").toString();
	card.subdivision = obj.take("subdivision").toString();
	card.surname = obj.take("surname").toString();
	card.brightnessCorrection = obj.take("brightness").toInt();
	card.contrastCorrection = obj.take("contrast").toInt();
	return card;
}

string passingEventToJSON(const PassingEvent &event)
{
	QJsonDocument doc;
	QJsonObject obj;
	obj.insert("id", event.id.toString());
	obj.insert("enterance", event.enterance);
	obj.insert("passed", event.passed);
	obj.insert("time", event.time.toString("yyyy.MM.dd.hh.mm.ss"));
	doc.setObject(obj);
	return doc.toJson().toStdString();
}

PassingEvent passingEventFromJSON(const string &str)
{
	PassingEvent event;
	QJsonDocument doc = QJsonDocument::fromJson(QByteArray::fromStdString(str));
	QJsonObject obj = doc.object();
	event.id = QUuid(obj.take("id").toString());
	event.enterance = obj.take("enterance").toBool();
	event.passed = obj.take("passed").toBool();
	event.time = QDateTime::fromString(obj.take("time").toString(), "yyyy.MM.dd.hh.mm.ss");
	return event;
}

ConnectionToServer::ConnectionToServer(QObject *parent)
	: QObject(parent), socket(ioc), resolver(ioc), in(&buff)
{
	running = false;
	lastSendingTime = QDateTime::currentDateTime();
}

void ConnectionToServer::connect(std::string ip, std::string port)
{
	boost::asio::connect(socket, resolver.resolve(ip, port));

	http::verb verb = http::verb::get;
	string query = "/connect";
	string host = ip + ":" + port;

	http::request<http::string_body> req(verb, query, 11);
	req.set(http::field::host, host);
	req.prepare_payload();

	http::write(socket, req);

	// Часть, отвечающая за чтение респонса
	boost::beast::flat_buffer buffer;
	http::response<http::string_body> res;
	http::read(socket, buffer, res);

	std::cout << res.body() << std::endl;
	// Закрываем соединение
	socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both);

	boost::asio::connect(socket, resolver.resolve(ip, res.body()));
	cout << "CONNECTED !!!!!!!!!!!!!!!!!" << endl;
}

void ConnectionToServer::run()
{
	running = true;
	std::thread t1 = std::thread([&]()
	{
		pinging();
	});
	t1.detach();
	std::thread t2 = std::thread([&]()
	{
		while(running)
		{
			this_thread::sleep_for(chrono::milliseconds(100));
			std::cout << "reading socket" << std::endl;
			boost::asio::read_until(socket, buff, '\n');
			string msg;
			getline(in, msg);

			cout << msg << endl;
			if (msg == "personal card added")
			{
				PersonalCard pc;
				if (!recvPersonalCard(pc))
				{
					// disconnect
				}
				emit personalCardAdded(pc);
				cout << personalCardToJSON(pc);
			}
			else if (msg == "personal card edited")
			{
				PersonalCard pc;
				if (!recvPersonalCard(pc))
				{
					// disconnect
				}
				emit personalCardEdited(pc);
				cout << personalCardToJSON(pc);
			}
			else if (msg == "personal card deleted")
			{
				PersonalCard pc;
				if (!recvPersonalCard(pc))
				{
					// disconnect
				}
				emit personalCardDeleted(pc);
				cout << personalCardToJSON(pc);
			}
			else if (msg == "sync")
			{
				sync();
			}
			else if (msg == "sending image")
			{
				cout << "recieving image" << endl;
				recvImage("Image1.png");
				cout << "recieved image" << endl;
			}
		}
	});
	t2.detach();
}

void ConnectionToServer::stop()
{
	running = false;
}

void ConnectionToServer::addPersonalCard(PersonalCard card)
{
	cout << "conn: PCA" << endl;
	string msg = "personal card added\n";
	msg += personalCardToJSON(card);
	msg += "!end!";
	boost::asio::const_buffer buff(msg.data(), msg.size());
	boost::asio::write(socket, buff);
	lastSendingTime = QDateTime::currentDateTime();
}

void ConnectionToServer::editPersonalCard(PersonalCard card)
{
	cout << "conn: PCE" << endl;
	string msg = "personal card edited\n";
	msg += personalCardToJSON(card);
	msg += "!end!";
	boost::asio::const_buffer buff(msg.data(), msg.size());
	boost::asio::write(socket, buff);
	lastSendingTime = QDateTime::currentDateTime();
}

void ConnectionToServer::deletePersonalCard(PersonalCard card)
{
	cout << "conn: PCD" << endl;
	string msg = "personal card deleted\n";
	msg += personalCardToJSON(card);
	msg += "!end!";
	boost::asio::const_buffer buff(msg.data(), msg.size());
	boost::asio::write(socket, buff);
	lastSendingTime = QDateTime::currentDateTime();
}

void ConnectionToServer::newPassingEvent(PassingEvent pe)
{
	cout << "NEW PASSING EVENT" << endl;
	string msg = "new passing event\n";
	msg += passingEventToJSON(pe);
	msg += "!end!";
	boost::asio::const_buffer buff(msg.data(), msg.size());
	boost::asio::write(socket, buff);
	lastSendingTime = QDateTime::currentDateTime();
}

void ConnectionToServer::imageAdded(QString fileName)
{
	string msg = "image added\n";
	msg += fileName.toStdString();
	msg += "\n";
	boost::asio::const_buffer buff(msg.data(), msg.size());
	boost::asio::write(socket, buff);
	sendImage(fileName.toStdString());
}

void ConnectionToServer::sync()
{
	lastSendingTime = QDateTime::currentDateTime();
	int num;
	in >> num;
	cout << num << endl;
	PersonalCard pc;
	for (int i = 0; i < num; ++i)
	{
		if (!recvPersonalCard(pc))
		{
			cout << "error" << endl;
		}
		cout << personalCardToJSON(pc) << endl;
	}
	lastSendingTime = QDateTime::currentDateTime();
}

bool ConnectionToServer::recvPersonalCard(PersonalCard &card, int millisec)
{
	bool recv = false;
	boost::asio::async_read_until(socket, buff, "!end!", [&](const boost::system::error_code& error, std::size_t bytes_transferred)
	{
		cout << "recv OK" << endl;
		recv = true;
		std::string msg(std::istreambuf_iterator<char>(in), {});
		msg = msg.substr(0, msg.size() - 5);
		card = personalCardFromJSON(msg);
	});
	ioc.reset();
	ioc.run_for(std::chrono::milliseconds(millisec));
	return recv;
}

void ConnectionToServer::pinging()
{
	while (running)
	{
		if (lastSendingTime.secsTo(QDateTime::currentDateTime()) >= 2)
		{
			string msg = "ping\n";
			boost::asio::const_buffer buff(msg.data(), msg.size());
			boost::asio::write(socket, buff);
			lastSendingTime = QDateTime::currentDateTime();
		}
		this_thread::sleep_for(chrono::milliseconds(100));
	}
}

bool ConnectionToServer::recvImage(const string &fileName, int millisec)
{
	atomic<bool> recv(false);
	int length;
	read_until(socket, buff, "\n");
	in >> length;
	cout << "image length " << length << endl;
	boost::asio::async_read(socket, buff, boost::asio::transfer_exactly(length - buff.size()), [&](const boost::system::error_code& error, std::size_t bytes_transferred)
	{
		cout << "recv length " << bytes_transferred << endl;
		recv = true;
		std::string msg(std::istreambuf_iterator<char>(in), {});
		writeImage(msg, fileName);
	});
	ioc.reset();
	ioc.run_for(std::chrono::milliseconds(millisec));
	return recv;
}

void ConnectionToServer::writeImage(const string &data, const string &fileName)
{
	ofstream f("./img/" + fileName);
	f.write(data.c_str(), data.size());
	f.close();
}

void ConnectionToServer::sendImage(const string &fileName)
{
	cout << "sending image " << fileName << endl;
	ifstream f("./img/" + fileName);
	f.seekg(0, std::ios::end);
	size_t size = f.tellg();
	cout << "sending size " << size << endl;
	std::string data(size, ' ');
	f.seekg(0);
	f.read(&data[0], size);
	f.close();

	int length = data.size();
	cout << "sending length " << length << endl;
	string strLen = to_string(length) + "\n";
	write(socket, boost::asio::const_buffer(strLen.data(), strLen.size()));
	write(socket, boost::asio::const_buffer(data.data(), data.size()));
}

PassingEvent::PassingEvent()
{

}

PassingEvent::PassingEvent(const PassingEvent &other)
{
	enterance = other.enterance;
	id = other.id;
	passed = other.passed;
	time = other.time;
}

PassingEvent::~PassingEvent()
{

}
