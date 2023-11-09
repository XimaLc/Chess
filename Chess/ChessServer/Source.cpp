//#include "Server.h"
#include "SFML/Network.hpp"
#include <iostream>
#include <optional>

int main()
{
	//SERVER

	sf::UdpSocket socket;
	unsigned short port = 8888;

	char in[128];
	std::size_t received;
	sf::IpAddress sender;
	unsigned short senderPort;
	
	while (true)
	{

	if (socket.bind(port) != sf::Socket::Status::Done)
		return 0;

	std::cout << "Server listening on port " << port << std::endl;


	if (socket.receive(in, sizeof(in), received, sender, senderPort) != sf::Socket::Status::Done)
		return 0;

	std::cout << "Message recu de " << sender << " : " << in << std::endl;

	if (socket.send(in, sizeof(in), sender, senderPort) != sf::Socket::Status::Done)
		return 0;

	std::cout << "Message envoye a " << sender << std::endl;
	}

	return 0;
}