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
	Map getPieces();

	void setPort(unsigned int _port);
	void send(const char* _data);


	void setColor(sf::Color _color);

	void fillPieces();
	void drawPieces(sf::RenderWindow& window);
	void setMapTexture(std::string _file);

	void resetPossibleMoves();
	void getPossibleMoves(int _x, int _y, Map oppenentMap);

	void editPiece(int _x, int _y, int _piece);

	bool move(int _x, int _y, sf::Vector2i _piece);
	bool eat(int _x, int _y, sf::Vector2i _piece, Player& oppenent);
};

