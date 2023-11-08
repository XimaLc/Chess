#include "Game.h"

void Game::loop()
{
	bool isRunning = true;
	while (isRunning)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
		}

		window.clear();
		map.draw(window);
		p1.drawPieces(window);
		//p2.drawPieces(window);
		window.display();
	}
}

Game::Game()
{
	window.create(sf::VideoMode(512, 512), "Chesstan");

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
