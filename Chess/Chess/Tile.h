#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

enum pieces {none, pawn, bishop, knight, rook, queen, king};
class Tile
{
private:
	int tileColor;
	int piece;

	sf::Texture tileTexture;
	sf::Texture pieceTexture;

	sf::Sprite tileSprite;
	sf::Sprite pieceSprite;

	sf::RectangleShape shape;
	sf::Vector2i pos;
public:
	void setPiece(int _piece);

	void draw(sf::RenderWindow& window, sf::Vector2f _pos);

	Tile();
	Tile(int _color);
	~Tile();
};

