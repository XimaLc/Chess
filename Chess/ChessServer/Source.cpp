#include "SFML/Network.hpp"
#include <fstream>
#include <iostream>
#include <optional>

int main()
{
	//SERVER

	sf::UdpSocket socket;
	unsigned short port = 15842;

	sf::IpAddress ipP1;
	sf::IpAddress ipP2;

	char in[128];
	std::size_t received;
	sf::IpAddress sender;
	unsigned short senderPort;

	sf::Packet packet;

	std::string fileName;

	bool player1Connected = false;
	bool player2Connected = false;

	if (socket.bind(port) != sf::Socket::Status::Done)
		return 0;

	std::cout << "Server listening on port " << port << std::endl;
	while (true)
	{
		if (socket.receive(in, sizeof(in), received, sender, port) != sf::Socket::Status::Done)
			return 0;

		std::cout << "Message reçu de " << sender << std::endl;
	}

	return 0;
}