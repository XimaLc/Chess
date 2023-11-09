//#include "Game.h"
#include "SFML/Network.hpp"
#include <iostream>
int main()
{
	//Game game;
	//CLIENT 
	sf::IpAddress server = "127.0.0.1";
	sf::UdpSocket socket;
	unsigned short port = 8888;
	std::string messageOut;

	while (true)
	{

		messageOut = "Salut la compagnie";
	

		if (socket.send(messageOut.c_str(), sizeof(messageOut), server, port) != sf::Socket::Status::Done)
			return 0;

		std::cout << "Message envoyé au serveur" << std::endl;

		char in[128];
		std::size_t received;
		sf::IpAddress sender;
		unsigned short senderPort;

		if (socket.receive(in, sizeof(in), received, sender, senderPort) != sf::Socket::Status::Done)
			return 0;

		std::cout << "Message recu de " << sender << ": " << in << std::endl;

		}
		return 0;
}