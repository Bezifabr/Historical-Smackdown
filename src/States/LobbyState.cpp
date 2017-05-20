#include "States\LobbyState.h"
#include "States\GameState.h"
#include "StatesMachine.h"
#include <iostream>

using std::cout;
using std::endl;

void LobbyState::Load()
{
	cout << "Lobby loaded" << endl;
}

void LobbyState::Unload()
{
	cout << "Lobby unloaded" << endl;
}

void LobbyState::Update(StatesMachine * statesMachine)
{
	statesMachine->Change(new GameState);
}

void LobbyState::HandleEvent(sf::Event event)
{
}

void LobbyState::Render(sf::RenderTarget & renderTarget)
{
}
