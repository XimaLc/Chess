#pragma once
#include "SFML/Network.hpp"
#include <iostream>

class Client
{
public:
	sf::IpAddress server;
	sf::UdpSocket socket;
	unsigned short port;
	std::string messageOut;
	sf::IpAddress oppenent;

	//void getOppenent();
	int sendMessage(std::string _message);
	std::string receiveMessage();
	std::string waitForInfo();
	Client();
};