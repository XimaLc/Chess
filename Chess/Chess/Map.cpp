#include "Map.h"

void Map::setTexture(std::string _file)
{
    texture.loadFromFile(_file);
    setSprite();
}

void Map::setSprite()
{
    sprite.setTexture(texture);
}

void Map::fill()
{
    int i = 0;
    for (int y = 0; y < 8; y++)
    {
        if (y % 2 == 0)
            i = 1;
        if (y % 2 > 0)
            i = 0;
        for (int x = 0; x < 8; x++)
        {
            map.push_back({ 0, i });
            i++;
            if (i == 2)
                i = 0;
        }
    }
}

void Map::white()
{
    for (int i = 0; i < 48; i++)
    {
        map.push_back(sf::Vector2i{ none, 0 });
    }
    for (int i = 48; i < 56; i++)
    {
        map.push_back(sf::Vector2i{ pawn, 0 });
    }
    map.push_back(sf::Vector2i{ rook, 0 });
    map.push_back(sf::Vector2i{knight, 0});
    map.push_back(sf::Vector2i{bishop, 0});
    map.push_back(sf::Vector2i{ queen, 0 });
    map.push_back(sf::Vector2i{ king, 0 });
    map.push_back(sf::Vector2i{ bishop, 0 });
    map.push_back(sf::Vector2i{ knight, 0 });
    map.push_back(sf::Vector2i{ rook, 0 });
}

void Map::black()
{
    map.push_back(sf::Vector2i{ rook, 0 });
    map.push_back(sf::Vector2i{ knight, 0 });
    map.push_back(sf::Vector2i{ bishop, 0 });
    map.push_back(sf::Vector2i{ king, 0 });
    map.push_back(sf::Vector2i{ queen, 0 });
    map.push_back(sf::Vector2i{ bishop, 0 });
    map.push_back(sf::Vector2i{ knight, 0 });
    map.push_back(sf::Vector2i{ rook, 0 });
    for (int i = 8; i < 16; i++)
    {
        map.push_back(sf::Vector2i{ pawn, 0 });
    }
    for (int i = 16; i < 64; i++)
    {
        map.push_back(sf::Vector2i{ none, 0 });
    }
}

void Map::draw(sf::RenderWindow& _window)
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

        rect = sf::IntRect(64 * map[i].x, 64 * map[i].y, 64, 64);

        sprite.setTextureRect(rect);
        sprite.setPosition(x * 64, y * 64);
        _window.draw(sprite);

        x++;
    }
}

Map::Map()
{
}
