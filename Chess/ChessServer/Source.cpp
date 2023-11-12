//#include "Server.h"
#include "SFML/Network.hpp"
#include <fstream>
#include <iostream>
#include <optional>

int main()
{
	//SERVER

	sf::UdpSocket socket;
	unsigned short port = 8888;
	unsigned short portP1;
	unsigned short portP2;
	

	sf::UdpSocket fileSocket;
	unsigned short filePort = 8887;

	char in[128];
	std::size_t received;
	sf::IpAddress sender;
	unsigned short senderPort;
	
	sf::Packet packet;

	std::string fileName;

	bool player1Connected = false;
	bool player2Connected = false;

	if (fileSocket.bind(filePort) != sf::Socket::Status::Done)
		return 0;
	
	if (fileSocket.receive(packet, sender, senderPort) == sf::Socket::Status::Done)
	{
		packet >> fileName;
		std::ofstream file("data\\" + fileName, std::ios::binary);
		if (file.is_open())
		{
			std::size_t fSize;
			packet >> fSize;

			char* fData = new char[fSize];
			packet >> fData;
			file.write(fData, fSize);

			delete[] fData;
			file.close();

			std::cout << "C bon" << std::endl;
		}
		else
		{
			std::cout << "Erreur a l'ouverture du fichier" << std::endl;
		}
	}

	if (socket.bind(port) != sf::Socket::Status::Done)
		return 0;

	while (true)
	{
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