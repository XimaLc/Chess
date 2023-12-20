#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
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

	void showKingMoves(int _x, int _y, Map _opponent);
	void showRookMoves(int _x, int _y, Map _opponent);
	void showBishopMoves(int _x, int _y, Map _opponent);
	void showKnightMoves(int _x, int _y, Map _opponent);
	void showPawnMoves(int _x, int _y, sf::Color _team, Map _opponent);
	void resetPossibleMoves();

	void editPiece(int _x, int _y, int _newPiece);
	void editPiece(sf::Vector2i _pos, int _newPiece);

	sf::Vector2i find(int _pieceId);

	bool isCheckedByRookAndMoitieDeQueen(int _x, int _y, Map opponent);
	bool isCheckedByBishopAndMoitieDeQueen(int _x, int _y, Map opponent);
	bool isCheckedByPawn(int _x, int _y, Map opponent);
	bool isCheckedByKnight(int _x, int _y, Map opponent);
	bool isCheckedByQueen(int _x, int _y, Map opponent);

	Map();
};