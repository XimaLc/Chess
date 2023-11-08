#include "Map.h"

Layer Map::getLayer(int _id)
{
    if (_id == 1)
        return map;
}

void Map::setLayer(int _id, Layer _layer)
{
    if (_id == 1)
        map = _layer;
}

void Map::setLayersTexture()
{
    map.setTexture("../Files/Textures/tiles.png");
    pieces.setTexture("../Files/Textures/pieces.png");
    setSprites();
}

void Map::setSprites()
{
    map.setSpriteTexture();
    pieces.setSpriteTexture();
}

void Map::setSpriteTextureRect(int _layerId, sf::IntRect _rect)
{
    if (_layerId == 1)
        map.setSpriteTextureRect(_rect);
}

void Map::setSpritePosition(int _layerId, int _x, int _y)
{
    if (_layerId == 1)
        map.setSpritePosition(_x, _y);
}

void Map::changeTileType(int _layerId, int _pos, int _newType)
{
    if (_layerId == 2)
        map.setTileY(_pos, _newType);
}

void Map::draw(sf::RenderWindow& _window)
{
    map.draw(_window);
    pieces.draw(_window);
}

bool Map::isPieceClicked(int _x, int _y)
{
    return pieces.isPieceClicked(_x, _y);
}

int Map::clickedPiece(int _x, int _y)
{
    return pieces.clickedPiece(_x, _y);
}

void Map::getPossibleMoves(int _x, int _y)
{
    pieces.getPossibleMoves(_x, _y);
}

void Map::removePreviousPossibleMoves()
{
    pieces.removePreviousPossibleMoves();
}

bool Map::isMovePossible(int _x, int _y)
{
    return pieces.isMovePossible(_x, _y);
}

Map::Map()
{
    map.fill();
    pieces.setup();
}

Map::~Map()
{
}
