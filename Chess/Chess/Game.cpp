#include "Game.h"

void Game::convert(int& _pos)
{
	int tmp = 0;
	for (int i = 7; i >= 0; i--)
	{
		if (_pos == tmp)
		{
			_pos = i;
			break;
		}
		tmp++;
	}
}

void Game::loop()
{
	float cd = 0.f;
	bool p1turn = true;
	bool p1played = false;
	bool p2turn = false;
	bool p2played = true;

	bool isRunning = true;

	int oppenentX;
	int oppenentY;
	int prevOppenentX;
	int prevOppenentY;


	sf::Vector2i clickedPiece = { 0, 0 };

	std::string res;

	//client.waitForInfo();

	//std::cout << "Mon adversaire est : " << client.oppenent << std::endl;


	while (isRunning)
	{
		cd += GetDeltaTime();
		sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
		int x = static_cast<int>(pixelPos.x / 64);
		int y = static_cast<int>(pixelPos.y / 64);
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
			}

			if (p1played)
			{
				p1turn = false;
				p2turn = true;
				p1played = false;
			}

			if (p2played)
			{
				p2turn = false;
				p1turn = true;
				p2played = false;
			}

			if (p1turn)
			{
				if (MOUSE(Left) && cd > 0.5f)
				{
					if (p1.getPieces().returnPiece(x, y) != 6 && p1.getPieces().returnPiece(x, y) != 7 && p1.getPieces().returnPiece(x, y) != 8)
					{
						clickedPiece = { x, y };
						p1.resetPossibleMoves();
						p1.getPossibleMoves(x, y, p2.getPieces());
					}
					else if (p1.getPieces().returnPiece(x, y) == 7)
					{
						p1played = p1.move(x, y, clickedPiece);
						client.sendMessage(std::string(std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(clickedPiece.x) + " " + std::to_string(clickedPiece.y)));
					}
					else if (p1.getPieces().returnPiece(x, y) == 8)
					{
						p1played = p1.eat(x, y, clickedPiece, p2);
						client.sendMessage(std::string(std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(clickedPiece.x) + " " + std::to_string(clickedPiece.y)));
					}
				}
			}
			else if (p2turn)
			{
				res.clear();
				while (res.empty())
				{
					res = client.waitForInfo();
				}
				std::cout << res << std::endl;
				oppenentX = stoi(res.substr(0, res.find(" ")));
				res.erase(0, 2);
				oppenentY = stoi(res.substr(0, res.find(" ")));
				res.erase(0, 2);
				prevOppenentX = stoi(res.substr(0, res.find(" ")));
				res.erase(0, 2);
				prevOppenentY = stoi(res.substr(0, res.find(" ")));

				convert(oppenentX);
				convert(oppenentY);
				convert(prevOppenentX);
				convert(prevOppenentY);

				if (p1.getPieces().returnPiece(oppenentX, oppenentY) != 6)
					p2played = p2.eat(oppenentX, oppenentY, prevOppenentX, prevOppenentY, p1);
				else if (p1.getPieces().returnPiece(oppenentX, oppenentY) == 6)
					p2played = p2.move(oppenentX, oppenentY, prevOppenentX, prevOppenentY);
			}

			window.clear();
			map.draw(window);
			p1.drawPieces(window);
			p2.drawPieces(window);
			window.display();

		}
	}
}

Game::Game()
{
	window.create(sf::VideoMode(512, 512), "Chesstan");

	p1.setPort(9666);
	p1.send("Salut !");
	p1.setColor(sf::Color::White);
	p2.setColor(sf::Color::Black);

	map.setTexture("../Files/Textures/tiles.png");
	p1.setMapTexture("../Files/Textures/piecesW.png");
	p2.setMapTexture("../Files/Textures/piecesB.png");

	map.fill();
	p1.fillPieces();
	p2.fillPieces();

	initTools();

	loop();
}