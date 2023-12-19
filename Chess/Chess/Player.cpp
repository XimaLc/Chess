#include "Player.h"

Map Player::getPieces()
{
	return pieces;
}

int Player::getPiece(int _x, int _y)
{
	return pieces.returnPiece({_x, _y});
}

void Player::setPort(unsigned int _port)
{
}

void Player::send(const char* _data)
{
}

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

void Player::resetPossibleMoves()
{
	pieces.resetPossibleMoves();
}

void Player::getPossibleMoves(int _x, int _y, Map opponentMap)
{
	int p = pieces.returnPiece(_x, _y);
	switch (p)
	{
	case 0:
		pieces.showKingMoves(_x, _y, opponentMap);
		break;

	case 1:
		pieces.showBishopMoves(_x, _y, opponentMap);
		pieces.showRookMoves(_x, _y, opponentMap);
		break;

	case 2:
		pieces.showRookMoves(_x, _y, opponentMap);
		break;

	case 3:
		pieces.showBishopMoves(_x, _y, opponentMap);
		break;

	case 4:
		pieces.showKnightMoves(_x, _y, opponentMap);
		break;
		
	case 5:
		pieces.showPawnMoves(_x, _y, color,opponentMap);
		break;
	}
}

void Player::editPiece(int _x, int _y, int _piece)
{
	pieces.editPiece(_x, _y, _piece);
}

bool Player::move(int _x, int _y, sf::Vector2i _piece)
{
	int piece = pieces.returnPiece(_piece);
	pieces.editPiece(_piece, 6);
	pieces.editPiece(_x, _y, piece);
	pieces.resetPossibleMoves();
	return true;
}

bool Player::move(int _x, int _y, int _prevX, int _prevY)
{
	int piece = pieces.returnPiece(_prevX, _prevY);
	pieces.editPiece(_prevX, _prevY, 6);
	pieces.editPiece(_x, _y, piece);
	pieces.resetPossibleMoves();
	return true;
}

int Player::eat(int _x, int _y, sf::Vector2i _piece, Player& opponent)
{
	if (opponent.getPiece(_x, _y) != 0)
	{
		int piece = pieces.returnPiece(_piece);
		pieces.editPiece(_piece, 6);
		pieces.editPiece(_x, _y, piece);
		opponent.editPiece(_x, _y, 6);
		pieces.resetPossibleMoves();
		return 1;
	}
	else
	{
		std::cout << "LOOOOOOOSER" << std::endl;
		return 2;
	}
}

int Player::eat(int _x, int _y, int _prevX, int _prevY, Player& opponent)
{
	if (opponent.getPiece(_x, _y) != 0)
	{
		int piece = pieces.returnPiece(_prevX, _prevY);
		pieces.editPiece(_prevX, _prevY, 6);
		pieces.editPiece(_x, _y, piece);
		opponent.editPiece(_x, _y, 6);
		pieces.resetPossibleMoves();
		return 1;
	}
	else
	{
		std::cout << "LOOOOOOOSER" << std::endl;
		return 2;
	}
	
}
