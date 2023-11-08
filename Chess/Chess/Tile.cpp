#include "Tile.h"

void Tile::setPiece(int _piece)
{
	piece = _piece;
}

void Tile::draw(sf::RenderWindow& window, sf::Vector2f _pos)
{
	if (tileColor == 0)
		shape.setFillColor(sf::Color::Black);
		
	if (tileColor == 1)
		shape.setFillColor(sf::Color::White);

	shape.setPosition(_pos);

	window.draw(shape);
}

Tile::Tile()
{
	tileTexture.loadFromFile("../Files/Textures/tiles.png");
	pieceTexture.loadFromFile("../Files/Textures/pieces.png");

	piece = 0;
	tileColor = 0;
}

Tile::Tile(int _color)
{
	tileTexture.loadFromFile("../Files/Textures/tiles.png");
	pieceTexture.loadFromFile("../Files/Textures/pieces.png");

	piece = 0;
	tileColor = _color;
}

Tile::~Tile()
{
}
