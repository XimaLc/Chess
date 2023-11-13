#include "Client.h"

std::string Client::receiveMessage()
{
	char in[128];
	std::size_t received;
	sf::IpAddress sender;
	
	if (socket.receive(in, sizeof(in), received, sender, port) != sf::Socket::Status::Done)
		return "0";

	return in;
}

int Client::sendMessage(std::string _message)
{
	//CLIENT 

	if (socket.send(_message.c_str(), sizeof(_message), server, port) != sf::Socket::Status::Done)
		return 0;

		std::cout << "Message envoyé au serveur" << std::endl;
}

std::string Client::waitForInfo()
{
	std::string res = "0";
	while (res == "0")
	{
		res = receiveMessage();
	}
	return res;
}

Client::Client()
{
	server = "192.168.10.106";
	//server = "127.0.0.1";
	port = 8888;
}