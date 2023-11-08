#pragma once
#include "Map.h"
#include <vector>
#include "SFML/Graphics.hpp"

class Player
{
private:
	sf::Color color;
	Map pieces;

public:
	void setColor(sf::Color _color);

	void fillPieces();
	void drawPieces(sf::RenderWindow& window);
	void setMapTexture(std::string _file);
};

