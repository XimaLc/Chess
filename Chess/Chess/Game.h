#pragma once
#include "Map.h"
#include "Player.h"
#include "Tools.h"
#include "Client.h"

class Game
{
private:
	Map map;
	Client client;
	Player p1;
	Player p2;

	sf::RenderWindow window;
public:
	void convert(int &_pos);
	void loop();

	Game();
};

