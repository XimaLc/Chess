#pragma once
#include "SFML/Network.hpp"
#include "Player.h"
#include <iostream>

class Client : public Player
{
public:
	sf::IpAddress ip;
	unsigned short port;

	sf::UdpSocket socket;
	std::string messageOut;
	sf::IpAddress oppenent;

	//void getOppenent();
	int sendMessage(std::string _message);
	std::string receiveMessage();
	std::string waitForInfo();
	Client();
};