#pragma once
#include "map.h"
#include "Tools.h"
class Game
{
private:
	Map map;
	sf::RenderWindow window;

public:
	void loop();

	Game();
	~Game();
};

