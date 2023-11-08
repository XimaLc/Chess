#include "Layer.h"

void Layer::setTexture(std::string _file)
{
    texture.loadFromFile(_file);
}

sf::Sprite Layer::getSprite()
{
    return sprite;
}

void Layer::setSpriteTexture()
{
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
}

void Layer::setSpriteTextureRect(sf::IntRect _rect)
{
    sprite.setTextureRect(_rect);
}

void Layer::setSpritePosition(int _x, int _y)
{
    sprite.setPosition(_x, _y);
}

std::vector<sf::Vector2i> Layer::getTiles()
{
    return tiles;
}

void Layer::setTiles(std::vector<sf::Vector2i> _tiles)
{
    tiles = _tiles;
}

void Layer::setTileY(int _pos, int _y)
{
    tiles[_pos].y = _y;
}

void Layer::setTileX(int _pos, int _x)
{
    tiles[_pos].x = _x;
}

void Layer::fill()
{
    int i = 0;
    for (int y2 = 0; y2 < 8; y2++)
    {
        if (y2%2 > 0)
            i = 1;
        if (y2 % 2 == 0)
            i = 0;
        for (int x2 = 0; x2 < 8; x2++)
        {
            tiles.push_back({ 0, i });
            i++;
            if (i == 2)
                i = 0;
        }
    }
}

void Layer::setup()
{
    tiles.push_back(sf::Vector2i{ 2, 0 });
    tiles.push_back(sf::Vector2i{ 3, 0 });
    tiles.push_back(sf::Vector2i{ 4, 0 });
    tiles.push_back(sf::Vector2i{ 0, 0 });
    tiles.push_back(sf::Vector2i{ 1, 0 });
    tiles.push_back(sf::Vector2i{ 4, 0 });
    tiles.push_back(sf::Vector2i{ 3, 0 });
    tiles.push_back(sf::Vector2i{ 2, 0 });
    for (int i = 8; i < 16; i++)
    {
        tiles.push_back(sf::Vector2i{ 5, 0 });
    }
    for (int i = 16; i < 48; i++)
    {
        tiles.push_back(sf::Vector2i{ 6, 0 });
    }
    for (int i = 48; i < 56; i++)
    {
        tiles.push_back(sf::Vector2i{ 5, 1 });
    }
    tiles.push_back(sf::Vector2i{ 2, 1 });
    tiles.push_back(sf::Vector2i{ 3, 1 });
    tiles.push_back(sf::Vector2i{ 4, 1 });
    tiles.push_back(sf::Vector2i{ 1, 1 });
    tiles.push_back(sf::Vector2i{ 0, 1 });
    tiles.push_back(sf::Vector2i{ 4, 1 });
    tiles.push_back(sf::Vector2i{ 3, 1 });
    tiles.push_back(sf::Vector2i{ 2, 1 });
}

bool Layer::isPieceClicked(int _x, int _y)
{
    if (tiles[_x + _y * 8].x != 6 && tiles[_x + _y * 8].x != 7)
        return true;
    else
        return false;
}

int Layer::clickedPiece(int _x, int _y)
{
    return tiles[_x + _y * 8].x;
}

bool Layer::isMovePossible(int _x, int _y)
{
    if (tiles[_x + _y * 8].x == 7)
        return true;
    else
        return false;
}

void Layer::getPossibleMoves(int _x, int _y)
{
    if (tiles[_x + _y * 8].y == 1 && _y > 1)
    {
        if (tiles[_x + (_y - 1) * 8].x == 6)
        {
            if (_y == 6)
            {
                tiles[_x + (_y - 1) * 8] = sf::Vector2i{ 7, 0 };
                tiles[_x + (_y - 2) * 8] = sf::Vector2i{ 7, 0 };
            }
            else
                tiles[_x + (_y - 1) * 8] = sf::Vector2i{ 7, 0 };
        }
    }
}

void Layer::removePreviousPossibleMoves()
{
    
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            int x = j + i * 8;
            if (tiles[i * 8 + j].x == 7)
            {
                tiles[i * 8 + j].x = 6;
            }
        }
    }
}

void Layer::draw(sf::RenderWindow& _window)
{

    int x = 0;
    int y = 0;
    sf::IntRect rect;

    for (int i = 0; i < 8 * 8; i++)
    {
        if (x == 8)
        {
            x = 0;
            y++;
        }

        rect = sf::IntRect(64 * tiles[i].x, 64 * tiles[i].y, 64, 64);

        sprite.setTextureRect(rect);
        sprite.setPosition(x * 64, y * 64);
        _window.draw(sprite);

        x++;
    }
}
