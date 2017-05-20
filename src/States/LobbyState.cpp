#include "States\LobbyState.h"
#include "States\GameState.h"
#include "StatesMachine.h"
#include <iostream>

using std::cout;
using std::endl;

void LobbyState::OnLoad()
{
	cout << "Lobby loaded" << endl;
}

void LobbyState::OnUnload()
{
	cout << "Lobby unloaded" << endl;
}

void LobbyState::Update()
{
	statesMachine->Change(new GameState);
}

void LobbyState::HandleEvent(sf::Event event)
{
}

void LobbyState::Render(sf::RenderTarget & renderTarget)
{
}
