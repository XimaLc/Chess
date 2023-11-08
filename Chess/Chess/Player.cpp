#include "Player.h"

void Player::setColor(sf::Color _color)
{
	color = _color;
}

void Player::fillPieces()
{
	if (color == sf::Color::White)
	{
		pieces.white();
	}

	if (color == sf::Color::Black)
	{
		pieces.black();
	}
}

void Player::drawPieces(sf::RenderWindow& window)
{
	pieces.draw(window);
}

void Player::setMapTexture(std::string _file)
{
	pieces.setTexture(_file);
}
