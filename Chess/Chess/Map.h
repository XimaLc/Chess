#pragma once
#include "Layer.h"
class Map
{
private:
	Layer map;
	Layer pieces;
public:
	Layer getLayer(int _id);
	void setLayer(int _id, Layer _layer);
	void setLayersTexture();


	void setSprites();
	void setSpriteTextureRect(int _layerId, sf::IntRect _rect);

	void setSpritePosition(int _layerId, int _x, int _y);


	void changeTileType(int _layerId, int _pos, int _newType);

	void draw(sf::RenderWindow& _window);

	bool isPieceClicked(int _x, int _y);
	int clickedPiece(int _x, int _y);

	void getPossibleMoves(int _x, int _y);
	void removePreviousPossibleMoves();
	
	bool isMovePossible(int _x, int _y);

	Map();
	~Map();
};

