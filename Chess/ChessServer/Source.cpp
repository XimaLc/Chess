//#include "Server.h"
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

	/*sf::UdpSocket fileSocket;
	unsigned short filePort = 8887;*/

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

	/*if (fileSocket.bind(filePort) != sf::Socket::Status::Done)
		return 0;*/

	/*if (!player1Connected)
	{
		if (fileSocket.receive(packet, ipP1, senderPort) == sf::Socket::Status::Done)
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

				std::cout << "Joueur 1 connecté avec l'ip : " << ipP1 << std::endl;
			} 
			else
				std::cout << "Erreur a l'ouverture du fichier" << std::endl;
		}
		player1Connected = true;
	}

	if (!player2Connected)
	{
		if (fileSocket.receive(packet, ipP2, senderPort) == sf::Socket::Status::Done)
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

				std::cout << "Joueur 2 connecté avec l'ip : " << ipP2 << std::endl;
			}
			else
			{
				std::cout << "Erreur a l'ouverture du fichier" << std::endl;
			}
		}*/
		//player2Connected = true;
		/*if (socket.send(ipP1.toString().c_str(), ipP1.toString().size(), ipP2, senderPort) != sf::Socket::Status::Done)
			return 0;*/
	//}

	std::cout << "Server listening on port " << port << std::endl;
	while (true)
	{

		
		if (socket.receive(in, sizeof(in), received, sender, port) != sf::Socket::Status::Done)
			return 0;

		std::cout << "Message reçu de " << sender << std::endl;

		/*if (sender == ipP1)
		{
		if (socket.send(in, sizeof(in), sender, senderPort) != sf::Socket::Status::Done)
			return 0;
		}

		if (sender == ipP2)
		{
			if (socket.send(in, sizeof(in), ipP1, senderPort) != sf::Socket::Status::Done)
				return 0;
		}*/

		//std::cout << "Message envoye a " << sender << std::endl;
	}

	return 0;
}