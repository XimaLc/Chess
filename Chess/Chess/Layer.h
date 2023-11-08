#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Layer
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

	std::vector<sf::Vector2i> tiles;
public:
	void setTexture(std::string _file);

	sf::Sprite getSprite();
	void setSpriteTexture();
	void setSpriteTextureRect(sf::IntRect _rect);
	void setSpritePosition(int _x, int _y);

	std::vector<sf::Vector2i> getTiles();
	void setTiles(std::vector<sf::Vector2i> _tiles);
	void setTileY(int _pos, int _y);
	void setTileX(int _pos, int _x);

	void fill();
	void setup();

	bool isPieceClicked(int _x, int _y);
	int clickedPiece(int _x, int _y);

	bool isMovePossible(int _x, int _y);

	void getPossibleMoves(int _x, int _y);
	void removePreviousPossibleMoves();

	void draw(sf::RenderWindow& _window);
};