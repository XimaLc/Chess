#include "Game.h"

void Game::loop()
{	
	float cd = 0.f;
	bool isRunning = true;
	initTools();
	while (isRunning)
	{
		restartClock();
		cd += GetDeltaTime();
		sf::Vector2i pixelPos = sf::Mouse::getPosition(window);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
			//sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
			int x = static_cast<int>(pixelPos.x / 64);
			int y = static_cast<int>(pixelPos.y / 64);
			if (MOUSE(Left) && cd > 0.5f)
			{
				
				if (map.isPieceClicked(x, y))
				{
					map.removePreviousPossibleMoves();
					int s = map.clickedPiece(x, y);
					switch (s)
					{
					case 0:
						std::cout << "Queen " << std::endl;
						break;
					case 1:
						std::cout << "King " << std::endl;
						break;
					case 2:
						std::cout << "Rook " << std::endl;
						break;
					case 3:
						std::cout << "Bishop " << std::endl;
						break;
					case 4:
						std::cout << "Knight " << std::endl;
						break;
					case 5:
						std::cout << "Pawn " << std::endl;
						map.getPossibleMoves(x, y);
						break;
					default:
						break;
					}
				}
				else if (map.isMovePossible(x, y))
				{
					
					map.removePreviousPossibleMoves();
				}
				cd = 0.f;
			}
		
		
		}

		

		window.clear();
		map.draw(window);
		window.display();
	}
}

Game::Game()
{
	map.setLayersTexture();
	window.create(sf::VideoMode(512, 512), "Editeur");
	

	loop();
}

Game::~Game()
{
}
