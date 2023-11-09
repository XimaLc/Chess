#pragma once
#include "SFML/Network.hpp"
class User
{
public:
	std::string name;
	std::string password;
	int elo;

	sf::IpAddress ip;
	unsigned short port;

	bool isActive = 0;
};

