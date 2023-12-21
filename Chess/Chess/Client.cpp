#include "Client.h"

std::string Client::receiveMessage()
{
	char in[128];
	in[127] = 1;
	std::size_t received;
	sf::IpAddress sender;

	if (socket.receive(in, sizeof(in), received, sender, port) != sf::Socket::Status::Done)
		return "0";

	return in;
}

int Client::sendMessage(std::string _message)
{
	if (socket.send(_message.c_str(), sizeof(_message), ip, port) != sf::Socket::Status::Done)
		return 0;

	std::cout << "Message envoye au serveur" << std::endl;
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
	ip = "127.0.0.1";
	port = 8888;
}