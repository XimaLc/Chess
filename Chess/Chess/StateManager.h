#pragma once
#include <iostream>
#include <map>
#include <SFML/Graphics/RenderWindow.hpp>

#include "State.h"
class StateManager
{
private:
	State* currentState;
	sf::RenderWindow* window;

	std::map<std::string, State*> states;
public:
	StateManager();
	~StateManager();

	void ChangeState(std::string _stateName);
	void Update();
	void Draw();
};

