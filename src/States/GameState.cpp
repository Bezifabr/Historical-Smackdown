#include "States\GameState.h"
#include "StatesMachine.h"
#include "MovementController.h"

#include <iostream>

using std::cout;
using std::endl;

void GameState::OnLoad()
{
	bgrTexture.loadFromFile("resources/textures/arenas/abbacy.png");
	background.setTexture(bgrTexture);

	player1.SetName("Mr. Hilter");
	player2.SetName("Cde. Spalin");

	player1.LoadTexture("resources/textures/characters/hilter.png");
	player2.LoadTexture("resources/textures/characters/spalin.png");

	player1.SetPosition(50, 775);
	player2.SetPosition(775, 775);

	basicMovement.SetMovementSpeed(20);
	basicMovement.SetMoveLeftKey(sf::Keyboard::A);
	basicMovement.SetMoveRightKey(sf::Keyboard::D);
	
	player1.SetMovementController(&basicMovement);


	cout << "Game loaded" << endl;
}

void GameState::OnUnload()
{
	cout << "Game unloaded" << endl;
}

void GameState::Update()
{
	player1.PerformMovement();
}

void GameState::HandleEvent(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		isGameFinished = true;
}

void GameState::Render(sf::RenderTarget & renderTarget)
{
	renderTarget.draw(background);
	player1.Render(renderTarget);
	player2.Render(renderTarget);
}
