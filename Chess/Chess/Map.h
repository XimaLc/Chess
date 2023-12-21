#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include "Tools.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>

enum Pieces {king, queen, rook, bishop, knight, pawn, none, move, atk};

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

	int returnPiece(int _x, int _y);
	int returnPiece(sf::Vector2i _pos);

	void draw(sf::RenderWindow& window);

	bool showKingMoves(int _x, int _y, Map _opponent, sf::Color team);
	void showRookMoves(int _x, int _y, Map _opponent, bool isChecked);
	void showBishopMoves(int _x, int _y, Map _opponent, bool isChecked);
	void showKnightMoves(int _x, int _y, Map _opponent, bool isChecked);
	void showPawnMoves(int _x, int _y, sf::Color _team, Map _opponent, bool isChecked);
	
	void resetPossibleMoves();

	void editPiece(int _x, int _y, int _newPiece);
	void editPiece(sf::Vector2i _pos, int _newPiece);

	sf::Vector2i find(int _pieceId);

	bool isCheckedByRookAndMoitieDeQueen(int _x, int _y, Map opponentMap);
	bool isCheckedByBishopAndMoitieDeQueen(int _x, int _y, Map opponentMap);
	bool isCheckedByPawn(int _x, int _y, Map opponentMap, sf::Color team);
	bool isCheckedByKnight(int _x, int _y, Map opponentMap);
	bool isCheckedByKing(int _x, int _y, Map opponentMap);

	sf::Vector2i getNearest(int _x, int _y, Map opponentMap, int _type);
	bool isCheckOrProtected(int _x, int _y, sf::Vector2i _player, sf::Vector2i _opponent, Map _opponentMap, sf::Vector2i _checkers);

	bool isNextCellCheckable(int _x, int _y, Map opponentMap, sf::Color team);

	Map();
};