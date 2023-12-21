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
	sf::Vector2i getPiece(int _x, int _y);

	void setColor(sf::Color _color);

	void fillPieces();
	void drawPieces(sf::RenderWindow& window);
	void setMapTexture(std::string _file, bool isPerso);

	void resetPossibleMoves();
	bool getPossibleMoves(int _x, int _y, Map opponentMap, bool isChecked);

	void editPiece(int _x, int _y, sf::Vector2i _piece);
	void editPiece(int _x, int _y, int _piece);

	bool move(int _x, int _y, sf::Vector2i _piece);
	bool move(int _x, int _y, int _prevX, int _prevY);

	int eat(int _x, int _y, sf::Vector2i _piece, Player& opponent);
	int eat(int _x, int _y, int _prevX, int _prevY, Player& opponent);


	bool checkIfChecked(Player oppopent);
	//bool checkIfChecked(int _x, int _y, Player oppopent);

	bool checkIfEnd(int _x, int _y, Player& opponent);
};

