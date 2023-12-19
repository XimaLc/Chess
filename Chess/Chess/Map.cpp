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
    //load();
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

void Map::showKingMoves(int _x, int _y, Map _opponentMap)
{
    if (_y < 7)
    {
        if (_opponentMap.returnPiece(_x, _y+1) != 6)
            editPiece(_x, _y + 1, 8);
        else if (map[(_x) + (_y + 1) * 8].x == 6)
            editPiece(_x, _y + 1, 7);
    }
    if (_y > 0)
    {
        if (_opponentMap.returnPiece(_x, _y - 1) != 6)
            editPiece(_x, _y - 1, 8);
        else if (map[(_x)+(_y - 1) * 8].x == 6)
            editPiece(_x, _y - 1, 7);
    }
    if (_x < 7)
    {
        if (_opponentMap.returnPiece(_x + 1, _y) != 6)
            editPiece(_x + 1, _y, 8);
        else if (map[(_x + 1)+(_y) * 8].x == 6)
            editPiece(_x + 1, _y, 7);
    }
    if (_x > 0)
    {
        if (_opponentMap.returnPiece(_x - 1, _y) != 6)
            editPiece(_x - 1, _y, 8);
        else if (map[(_x - 1) + (_y) * 8].x == 6)
            editPiece(_x - 1, _y, 7);
    }
    if (_y > 0 && _x < 7)
    {
        if (_opponentMap.returnPiece(_x + 1 , _y - 1) != 6)
            editPiece(_x + 1, _y - 1, 8);
        else if (map[(_x + 1)+(_y - 1) * 8].x == 6)
            editPiece(_x + 1, _y - 1, 7);
    }
    if (_y > 0 && _x > 0)
    {
        if (_opponentMap.returnPiece(_x - 1, _y - 1) != 6)
            editPiece(_x - 1, _y - 1, 8);
        else if (map[(_x - 1)+(_y - 1) * 8].x == 6)
            editPiece(_x - 1, _y - 1, 7);
    }
    if (_y < 7 && _x < 7)
    {
        if (_opponentMap.returnPiece(_x + 1, _y + 1) != 6)
            editPiece(_x + 1, _y + 1, 8);
        else if (map[(_x + 1)+(_y + 1) * 8].x == 6)
            editPiece(_x + 1, _y + 1, 7);
    }
    if (_y < 7 && _x > 0)
    {
        if (_opponentMap.returnPiece(_x - 1, _y + 1) != 6)
            editPiece(_x - 1, _y + 1, 8);
        else if (map[(_x - 1)+(_y + 1) * 8].x == 6)
            editPiece(_x - 1, _y + 1, 7);
    }

}

void Map::showRookMoves(int _x, int _y, Map _opponentMap)
{
    for (int i = 1; i < 8; i++)
    {
        if (_y-i >= 0)
        {
            int piece = returnPiece(_x, _y - i);
            int opponentPiece = _opponentMap.returnPiece(_x, _y - i);
            if (piece != 6)
                i = 8;
                
            if (piece == 6 && opponentPiece == 6)
                editPiece(_x, _y - i, 7);


            if (opponentPiece != 6)
            {
                editPiece(_x, _y - i, 8);
                i = 8;
            }

        }
    }
    for (int i = 1; i < 8; i++)
    {
        if (_y+i <= 7)
        {
            int piece = returnPiece(_x, _y + i);
            int opponentPiece = _opponentMap.returnPiece(_x, _y + i);

            if (piece != 6)
                i = 8;

            if (piece == 6 && opponentPiece == 6)
                editPiece(_x, _y + i, 7);
            if (opponentPiece != 6)
            {
                editPiece(_x, _y + i, 8);
                i = 8;
            }
        }
    }
    for (int i = 1; i < 8; i++)
    {
        if (_x - i >= 0)
        {
            int piece = returnPiece(_x - i, _y);
            int opponentPiece = _opponentMap.returnPiece(_x - i, _y);
            if (piece != 6)
                i = 8;

            if (piece == 6 && opponentPiece == 6)
                editPiece(_x - i, _y, 7);


            if (opponentPiece != 6)
            {
                editPiece(_x - i, _y, 8);
                i = 8;
            }

        }
    }
    for (int i = 1; i < 8; i++)
    {
        if (_x + i <= 7)
        {
            int piece = returnPiece(_x + i, _y);
            int opponentPiece = _opponentMap.returnPiece(_x + i, _y);

            if (piece != 6)
                i = 8;

            if (piece == 6 && opponentPiece == 6)
                editPiece(_x + i, _y, 7);
            if (opponentPiece != 6)
            {
                editPiece(_x + i, _y, 8);
                i = 8;
            }
        }
    }
}
void Map::showBishopMoves(int _x, int _y, Map _opponentMap)
{
    for (int i = 1; i < 8; i++)
    {
        if (_y - i >= 0 && _x - i >= 0)
        {
            int piece = returnPiece(_x - i, _y - i);
            int opponentPiece = _opponentMap.returnPiece(_x - i, _y - i);
            if (piece != 6)
                i = 8;

            if (piece == 6 && opponentPiece == 6)
                editPiece(_x - i, _y - i, 7);


            if (opponentPiece != 6)
            {
                editPiece(_x - i, _y - i, 8);
                i = 8;
            }

        }
    }
    for (int i = 1; i < 8; i++)
    {
        if (_y + i <= 7 && _x + i <= 7)
        {
            int piece = returnPiece(_x + i, _y + i);
            int opponentPiece = _opponentMap.returnPiece(_x + i, _y + i);

            if (piece != 6)
                i = 8;

            if (piece == 6 && opponentPiece == 6)
                editPiece(_x + i, _y + i, 7);
            if (opponentPiece != 6)
            {
                editPiece(_x + i, _y + i, 8);
                i = 8;
            }
        }
    }
    for (int i = 1; i < 8; i++)
    {
        if (_y - i >= 0 && _x + i <= 7) 
        {
            int piece = returnPiece(_x + i, _y - i);
            int opponentPiece = _opponentMap.returnPiece(_x + i, _y - i);
            if (piece != 6)
                i = 8;

            if (piece == 6 && opponentPiece == 6)
                editPiece(_x + i, _y - i, 7 );


            if (opponentPiece != 6)
            {
                editPiece(_x + i, _y - i, 8);
                i = 8;
            }

        }
    }
    for (int i = 1; i < 8; i++)
    {
        if (_y + i <= 7 && _x - i >= 0)
        {
            int piece = returnPiece(_x - i, _y + i);
            int opponentPiece = _opponentMap.returnPiece(_x - i, _y + i);

            if (piece != 6)
                i = 8;

            if (piece == 6 && opponentPiece == 6)
                editPiece(_x - i, _y + i, 7);
            if (opponentPiece != 6)
            {
                editPiece(_x - i, _y + i, 8);
                i = 8;
            }
        }
    }
}
void Map::showKnightMoves(int _x, int _y, Map _opponentMap)
{
    if (_y < 6 && _x > 0)
    {
        if (_opponentMap.returnPiece(_x - 1, _y + 2) != 6)
            editPiece(_x - 1, _y + 2, 8);
        else if (map[(_x - 1) + (_y + 2) * 8].x == 6)
            editPiece(_x - 1, _y + 2, 7);
    }
    if (_y < 6 && _x < 7)
    {
        if (_opponentMap.returnPiece(_x + 1, _y + 2) != 6)
            editPiece(_x + 1, _y + 2, 8);
        else if (map[(_x + 1) + (_y + 2) * 8].x == 6)
            editPiece(_x + 1, _y + 2, 7);
    }

    if (_y > 1 && _x < 7)
    {
        if (_opponentMap.returnPiece(_x + 1, _y - 2) != 6)
            editPiece(_x + 1, _y - 2, 8);
        else if (map[(_x + 1) + ((_y - 2) * 8)].x == 6)
            editPiece(_x + 1, _y - 2, 7);
    }

    if (_y > 1 && _x > 0)
    {
        if (_opponentMap.returnPiece(_x - 1, _y - 2) != 6)
            editPiece(_x - 1, _y - 2, 8);
        else if (map[(_x - 1) + (_y - 2) * 8].x == 6)
            editPiece(_x - 1, _y - 2, 7);
    }

    if (_y > 0 && _x > 1)
    {
        if (_opponentMap.returnPiece(_x - 2, _y - 1) != 6)
            editPiece(_x - 2, _y - 1, 8);
        else if (map[(_x - 2) + (_y - 1) * 8].x == 6)
            editPiece(_x - 2, _y - 1, 7);
    }

    if (_y > 0 && _x < 6)
    {
        if (_opponentMap.returnPiece(_x + 2, _y - 1) != 6)
            editPiece(_x + 2, _y - 1, 8);
        else if (map[(_x + 2) + (_y - 1) * 8].x == 6)
            editPiece(_x + 2, _y - 1, 7);
    }

    if (_y < 7 && _x > 1)
    {
        if (_opponentMap.returnPiece(_x - 2, _y + 1) != 6)
            editPiece(_x - 2, _y + 1, 8);
        else if (map[(_x - 2) + (_y + 1) * 8].x == 6)
            editPiece(_x - 2, _y + 1, 7);
    }

    if (_y < 7 && _x < 6)
    {
        if (_opponentMap.returnPiece(_x + 2, _y + 1) != 6)
            editPiece(_x + 2, _y + 1, 8);
        else if (map[(_x + 2) + (_y + 1) * 8].x == 6)
            editPiece(_x + 2, _y + 1, 7);
    }
}
void Map::showPawnMoves(int _x, int _y, sf::Color _team, Map _opponentMap)
{
    if (_team == sf::Color::White)
    {
        if (_x < 7 && _y > 0)
            if (_opponentMap.returnPiece(_x + 1, _y - 1) != 6)
                editPiece(_x + 1, _y - 1, 8);

        if (_x > 0 && _y > 0)
            if (_opponentMap.returnPiece(_x - 1, _y - 1) != 6)
                editPiece(_x - 1, _y - 1, 8);

        if (_y == 6)
            if (_opponentMap.returnPiece(_x, _y - 1) == 6 && returnPiece(_x, _y - 1) == 6)
            {
                editPiece(_x, _y - 1, 7);
                if (_opponentMap.returnPiece(_x, _y - 2) == 6 && returnPiece(_x, _y - 2) == 6)
                    editPiece(_x, _y - 2, 7);
            }
        
        if (_y < 6 && _y > 0)
            if (_opponentMap.returnPiece(_x, _y - 1) == 6 && returnPiece(_x, _y - 1) == 6)
                editPiece(_x, _y - 1, 7);
    }

    if (_team == sf::Color::Black)
    {
        if (_x > 0 && _y < 7)
            if (_opponentMap.returnPiece(_x - 1, _y + 1) != 6)
                editPiece(_x - 1, _y + 1, 8);

        if (_x < 7 && _y < 7)
            if (_opponentMap.returnPiece(_x + 1, _y + 1) != 6)
                editPiece(_x + 1, _y + 1, 8);

        if (_y == 1)
            if (_opponentMap.returnPiece(_x, _y + 1) == 6 && returnPiece(_x, _y + 1) == 6)
            {
                editPiece(_x, _y + 1, 7);
                if (_opponentMap.returnPiece(_x, _y + 2) == 6 && returnPiece(_x, _y + 2) == 6)
                    editPiece(_x, _y + 2, 7);
            }
        
        if (_y < 7)
            if (_opponentMap.returnPiece(_x, _y + 1) == 6 && map[_x + (_y + 1) * 8].x == 6)
                editPiece(_x, _y + 1, 7);
    }

}

void Map::resetPossibleMoves()
{
    for (int y = 0; y < 8; y++)
    {
        for (int x = 0; x < 8; x++)
        {
            if (map[x + y * 8].x == 7 || map[x + y * 8].x == 8)
            {
                map[x + y * 8].x = 6;
            }
        }
    }
}

void Map::editPiece(int _x, int _y, int _newPiece)
{
    map[_x + _y * 8].x = _newPiece;
}

void Map::editPiece(sf::Vector2i _pos, int _newPiece)
{
    map[_pos.x + _pos.y * 8].x = _newPiece;
}


int Map::returnPiece(int _x, int _y)
{
    return map[_x + _y * 8].x;
}

int Map::returnPiece(sf::Vector2i _pos)
{
    return map[_pos.x + _pos.y * 8].x;
}

Map::Map()
{
    
}