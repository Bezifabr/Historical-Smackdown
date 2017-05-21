#include "States\GameState.h"
#include "StatesMachine.h"

#include <iostream>

using std::cout;
using std::endl;

void GameState::OnLoad()
{
	bgrTexture.loadFromFile("resources/textures/arenas/abbacy.png");
	background.setTexture(bgrTexture);

	player1.SetName("Mr. Hilter");
	player2.SetName("Cde. Spalin");

	player1.LoadTexture("resources/textures/characters/HilterSprite.png");
	player2.LoadTexture("resources/textures/characters/spalin.png");

	player1.SetPosition(50, 775);
	player2.SetPosition(775, 775);

	basicMovement.SetMovementSpeed(30);
	basicMovement.SetMoveLeftKey(sf::Keyboard::A);
	basicMovement.SetMoveRightKey(sf::Keyboard::D);

	jumpMovement.SetFloorLevelY(775);
	jumpMovement.SetGravity(5);
	jumpMovement.SetJumpingForce(200);
	jumpMovement.SetJumpKey(sf::Keyboard::W);

	stand.AddFrame(sf::IntRect(656, 0, 164, 164));
	stand.AddFrame(sf::IntRect(656, 164, 164, 164));
	stand.SetTimeBetweenFrames(sf::seconds(0.5f));
	
	player1.SetAnimation(stand);
	player1.AddMovementController(&jumpMovement);
	player1.AddMovementController(&basicMovement);


	cout << "Game loaded" << endl;
}

void GameState::OnUnload()
{
	cout << "Game unloaded" << endl;
}

void GameState::OnUpdate()
{
	player1.PerformMovement(deltaTime);

	if (player1.GetPosition().x > player2.GetPosition().x)
		player1.TurnLeft();
	else if (player1.GetPosition().x < player2.GetPosition().x)
		player1.TurnRight();

	if (player2.GetPosition().x > player1.GetPosition().x)
		player2.TurnLeft();
	else if (player2.GetPosition().x < player1.GetPosition().x)
		player2.TurnRight();

	player1.PerformAnimation(deltaTime);

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
