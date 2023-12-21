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

	int opponentX;
	int opponentY;
	int prevopponentX;
	int prevopponentY;

	std::string winner = "";
	bool end = false;

	sf::Vector2i clickedPiece = { 0, 0 };

	sf::Font font;
	font.loadFromFile("../Files/Fonts/Ghost_Stories_Deluxe.ttf");

	sf::Text text;
	text.setFont(font);
	text.setPosition(120, 150);

	sf::RectangleShape button;
	button.setSize({ 150, 50 });
	button.setFillColor(sf::Color(211, 211, 211));
	button.setPosition(160, 200);

	sf::Text buttonText;
	buttonText.setFont(font);
	buttonText.setString("Rejouer");
	buttonText.setPosition(button.getPosition().x + 10, button.getPosition().y + 7);

	bool isP1Checked = false;
	bool isP2Checked = false;

	std::string res;
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

			if(!end)
			{
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
						if (pixelPos.x > 0 && pixelPos.x < window.getSize().x && pixelPos.y > 0 && pixelPos.y < window.getSize().y)
						{
							if (p1.getPieces().returnPiece(x, y) != 6 && p1.getPieces().returnPiece(x, y) != 7 && p1.getPieces().returnPiece(x, y) != 8)
							{
								clickedPiece = { x, y };
								p1.resetPossibleMoves();
								end = p1.getPossibleMoves(x, y, p2.getPieces(), isP2Checked);
								if (end)
									winner = "BLACK";
							}
							else if (p1.getPieces().returnPiece(x, y) == 7)
							{
								p1played = p1.move(x, y, clickedPiece);

								isP2Checked = p2.checkIfChecked(p1);
								std::cout << isP2Checked << " / P2 - 1" << std::endl;

								isP1Checked = p1.checkIfChecked(p2);
								std::cout << isP1Checked << " / P1 - 3" << std::endl;
							}
							else if (p1.getPieces().returnPiece(x, y) == 8)
							{
								end = p1.checkIfEnd(x, y, p2);
								if (end)
									winner = "WHITE";
								p1played = p1.eat(x, y, clickedPiece, p2);

								isP2Checked = p2.checkIfChecked(p1);
								std::cout << isP2Checked << " / P2 - 2" << std::endl;

								isP1Checked = p1.checkIfChecked(p2);
								std::cout << isP1Checked << " / P1 - 4" << std::endl;
							}
						}
					}
				}
				else if (p2turn)
				{
					if (MOUSE(Left) && cd > 0.5f)
					{
						if (pixelPos.x > 0 && pixelPos.x < window.getSize().x && pixelPos.y > 0 && pixelPos.y < window.getSize().y)
						{
							if (p2.getPieces().returnPiece(x, y) != 6 && p2.getPieces().returnPiece(x, y) != 7 && p2.getPieces().returnPiece(x, y) != 8)
							{
								clickedPiece = { x, y };
								p2.resetPossibleMoves();
								end = p2.getPossibleMoves(x, y, p1.getPieces(), isP2Checked);
								if (end)
									winner = "WHITE";
							}
							else if (p2.getPieces().returnPiece(x, y) == 7)
							{
								p2played = p2.move(x, y, clickedPiece);

								isP1Checked = p1.checkIfChecked(p2);
								std::cout << isP1Checked << " / P1 - 1" << std::endl;

								isP2Checked = p2.checkIfChecked(p1);
								std::cout << isP2Checked << " / P2 - 3" << std::endl;
							}
							else if (p2.getPieces().returnPiece(x, y) == 8)
							{
								end = p2.checkIfEnd(x, y, p1);
								if (end)
									winner = "BLACK";
								p2played = p2.eat(x, y, clickedPiece, p1);

								isP1Checked = p1.checkIfChecked(p2);
								std::cout << isP1Checked << " / P1 - 2" << std::endl;

								isP2Checked = p2.checkIfChecked(p1);
								std::cout << isP2Checked << " / P2 - 4" << std::endl;
							}
						}
					}

				}
			}
			else
			{
				if (MOUSE(Left) && cd > 0.5f)
				{
					if (button.getGlobalBounds().contains(static_cast<sf::Vector2f>(pixelPos)))
					{
						reset();
						loop();
					}
				}
			}
		}
		window.clear();
		if (!end)
		{
			map.draw(window);
			p1.drawPieces(window);
			p2.drawPieces(window);
		}
		else
		{
			text.setString("Gagnant : " + winner);
			window.draw(text);

			window.draw(button);
			window.draw(buttonText);
		}
		window.display();
	}
}

void Game::reset()
{
	map.fill();
	p1.fillPieces();
	p2.fillPieces();
}

Game::Game()
{
	window.create(sf::VideoMode(512, 512), "Chessthan");

	p1.setColor(sf::Color::White);
	p2.setColor(sf::Color::Black);

	map.setTexture("../Files/Textures/tilesPerso.png");
	p1.setMapTexture("../Files/Textures/piecesW.png");
	p2.setMapTexture("../Files/Textures/piecesB.png");

	map.fill();
	p1.fillPieces();
	p2.fillPieces();

	initTools();

	loop();
}