#include "States\GameState.h"
#include "StatesMachine.h"

#include <iostream>

using std::cout;
using std::endl;

void GameState::OnLoad()
{
	cout << "Game loaded" << endl;
}

void GameState::OnUnload()
{
	cout << "Game unloaded" << endl;
}

void GameState::Update()
{
	
}

void GameState::HandleEvent(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
		isGameFinished = true;
}

void GameState::Render(sf::RenderTarget & renderTarget)
{
}
