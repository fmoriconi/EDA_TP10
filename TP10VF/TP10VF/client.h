#pragma once


#define WIN32_LEAN_AND_MEAN

#include <iostream>
#include <cstdio>
#include <boost/asio.hpp>
#include <boost/chrono.hpp>
#include <boost/timer/timer.hpp>
#include <fstream>
using namespace std;
class client
{
public:
	client();
	client(const char * parser, const char * port);

	void connect(const char* host, const char * port);

	void receiveMessage();//recibe el mensaje de la pagina y lo transcribe bit a bit a un archivo llamado "archivo.xml"
						//siempre se queda esperando 10 segundos a que llegue toda la informacion
	void sendMessage(const char * msg);	//con este mando todo el GET HOST y la linea en blanco que sale si haces "\n"(0d 0a)
										//pasarle todo ese mensaje como un string concatenado de los 3 agregandole un \n despues de HTTP 1.1 y del Host
	void sendMessage();					//misma funcion pero sobrecargada para mandar el mensage directamento utilizando el dato miembro

	std::string getRss(char* argv);

	void prepareMessage(const char * parser); //setea host y rss a partir del parser


	//setter y getters por si se desea modificar algo

	void setHost(std::string host_) { this->host = host_; };
	void setRss(std::string rss_) { this->rss = rss_; };
	void setPort(const char * port_) { this->port = port_; };
	void setParser(const char * parser) { this->parserline = parser; };

	string Gethost() { return this->host; };
	string GetRss() { return this->rss; };
	string getMessage() { return message; };
	string getPort() { return port; };
	string getParser() { return parserline; };



	~client();							

private:
	boost::asio::io_service* IO_handler;
	boost::asio::ip::tcp::socket* socket_forClient;
	boost::asio::ip::tcp::resolver* client_resolver;
	boost::asio::ip::tcp::resolver::iterator endpoint;
	const char * parserline;
	string host;
	string rss;
	const char * port;
	std::string message;
	
};

