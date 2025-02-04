#include "StateManager.h"
#include "MenuState.h"
#include "GameState.h"

StateManager::StateManager()
{
	MenuState menuState;
	GameState gameState;

	states.insert({ "menu", &menuState });
	states.insert({ "game", &gameState });

	currentState = states["menu"];

	window = new sf::RenderWindow();
	window->create(sf::VideoMode(512, 512), "Chessthan");
}

StateManager::~StateManager()
{
	delete currentState;
	
	delete states["menu"];
	delete states["game"];
	delete window;
}

void StateManager::ChangeState(std::string _stateName)
{
	currentState = states[_stateName];
}

void StateManager::Update()
{
	currentState->Update();
}

void StateManager::Draw()
{
	currentState->Draw(*window);
}
