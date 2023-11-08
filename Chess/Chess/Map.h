#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>

enum Pieces {queen, king, rook, bishop, knight, pawn, none, move, atk};

class Map
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

	std::vector<sf::Vector2i> map;
public:
	void setTexture(std::string _file);
	void setSprite();

	void fill();
	void white();
	void black();


	void draw(sf::RenderWindow& window);

	Map();
};

