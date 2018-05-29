#include "client.h"
#include <iostream>

using namespace std;

client::client()
{
	IO_handler = new boost::asio::io_service();
	socket_forClient = new boost::asio::ip::tcp::socket(*IO_handler);
	client_resolver = new boost::asio::ip::tcp::resolver(*IO_handler);
}

client::client(const char * parser, const char * port)
{
	IO_handler = new boost::asio::io_service();
	socket_forClient = new boost::asio::ip::tcp::socket(*IO_handler);
	client_resolver = new boost::asio::ip::tcp::resolver(*IO_handler);
	this->parserline = parser;
	this->port = port;
	prepareMessage(parser);
}

void client::connect(const char * host, const char * port)
{
	endpoint = client_resolver->resolve(
		boost::asio::ip::tcp::resolver::query(host,port ));
	boost::asio::connect(*socket_forClient, endpoint);
	socket_forClient->non_blocking(true);
	std::cout << "conecto" << std::endl;
}

void client::receiveMessage()
{
	
	ofstream archivo("archivo.xml", ios::binary);

	boost::system::error_code error;
	char buf[0xFFFF];
	size_t len = 0;
	boost::timer::cpu_timer t;
	t.start();
	boost::timer::cpu_times pastTime = t.elapsed();
	double elapsedSeconds = 0.0;
	do
	{
		len = socket_forClient->read_some(boost::asio::buffer(buf,512), error);

		boost::timer::cpu_times currentTime = t.elapsed();

		if ((currentTime.wall - pastTime.wall) > 1e9)	//controla los 10 segundos 
		{												//se puede sacar el cout despues
			elapsedSeconds += (currentTime.wall - pastTime.wall) / 1e9;
			pastTime = currentTime;
			cout << "Pasaron " << elapsedSeconds << " segundos." << endl;
			
		}

		if (!error)
			buf[len] = '\0';
	
		if (!error)
		{
		//	std::cout << buf;	//con este cout si tarda bastante sino no tarda ni un segundo
			archivo<<buf;
		//	teste << buf;
		}
	} while (elapsedSeconds < 10.0);	//se trata de leer todo el rss en 10 segundos esto se puede cambiar 

	//if (!error)
		//std::cout << std::endl << "Server sais: " << buf;
	if (error)
		std::cout << "Error while trying to connect to server " << error.message() << std::endl;

	archivo.close();
//	teste.close();
}

void client::sendMessage(const char * msg)
{
	size_t len;
	boost::system::error_code error;

	do
	{
		len = socket_forClient->write_some(boost::asio::buffer(msg, strlen(msg)), error);
	} while ((error.value() == WSAEWOULDBLOCK));
	if (error)
		std::cout << "Error while trying to connect to server " << error.message() << std::endl;
}

void client::sendMessage()
{
	size_t len;
	boost::system::error_code error;

	do
	{
		len = socket_forClient->write_some(boost::asio::buffer((message.c_str()), strlen((message.c_str()))), error);
	} while ((error.value() == WSAEWOULDBLOCK));
	if (error)
		std::cout << "Error while trying to connect to server " << error.message() << std::endl;
}


void client::prepareMessage(const char * parser)
{
	string firstp = "";
	string secondp = "";
	stringstream aux(parser);
	getline(aux, firstp, '/');
	getline(aux, secondp);
	host = (firstp);
	rss = ("/" + secondp);
	secondp = "GET /" + secondp + " HTTP/1.1\n";				//le pongo la barra ahi despuesdel get pq se borra cuando haces el getline
	firstp = "Host: " + firstp + "\n";
	string Final = secondp + firstp + "\n";
	this->message = Final;
}

client::~client()
{
	socket_forClient->close();
	delete client_resolver;
	delete socket_forClient;
	delete IO_handler;

}
