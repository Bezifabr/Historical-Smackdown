#include "States\GameState.h"
#include "States\OverState.h"
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

	punchFighting.SetDamage(10);
	punchFighting.SetHitBox(sf::FloatRect(45,35,73,65));
	punchFighting.SetKey(sf::Keyboard::G);
	punchFighting.LoadSound("resources/sounds/punch.wav");

	Animation stand;
	stand.AddFrame(sf::IntRect(656, 0, 164, 164));
	stand.AddFrame(sf::IntRect(656, 164, 164, 164));
	stand.SetTimeBetweenFrames(sf::seconds(0.5f));

	Animation walk;
	walk.AddFrame(sf::IntRect(820, 0, 164, 164));
	walk.AddFrame(sf::IntRect(820, 164, 164, 164));
	walk.SetTimeBetweenFrames(sf::seconds(0.4f));

	Animation jump;
	jump.AddFrame(sf::IntRect(164, 0, 164, 164));
	jump.AddFrame(sf::IntRect(164, 0, 164, 164));
	jump.SetTimeBetweenFrames(sf::seconds(0.01f));

	Animation dead(stand); // temporary it has stand animation

	Animation punch;
	punch.AddFrame(sf::IntRect(492, 0, 164, 164));
	punch.AddFrame(sf::IntRect(492, 0, 164, 164));
	punch.SetTimeBetweenFrames(sf::seconds(0.01f));

	player1.AddAnimation(CharStateID::IDLE, stand);
	player1.AddAnimation(CharStateID::WALK, walk);
	player1.AddAnimation(CharStateID::JUMP, jump);
	player1.AddAnimation(CharStateID::DEAD, dead);
	player1.AddAnimation(CharStateID::PUNCH, punch);
	player1.AddMovementController(&jumpMovement);
	player1.AddMovementController(&basicMovement);
	player1.AddFightingController(&punchFighting);

	player1.SetHealth(100);
	player2.SetHealth(100);

	healthBarEmptyTexture.loadFromFile("resources/textures/GUI/Health_bar_empty.png");
	healthBarFullTexture.loadFromFile("resources/textures/GUI/Health_bar.png");

	healthBarEmpty1.setTexture(healthBarEmptyTexture);
	healthBarEmpty2.setTexture(healthBarEmptyTexture);
	healthBarFull1.setTexture(healthBarFullTexture);
	healthBarFull2.setTexture(healthBarFullTexture);

	healthBarEmpty1.setPosition(50, 50);
	healthBarFull1.setPosition(50, 50);
	healthBarEmpty2.setPosition(700, 50);
	healthBarFull2.setPosition(700, 50);


	cout << "Game loaded" << endl;
}

void GameState::OnUnload()
{
	cout << "Game unloaded" << endl;
}

void GameState::OnUpdate()
{
	player1.SetCharacterState(CharStateID::IDLE);
	player1.PerformMovement(deltaTime);
	player1.PerformAnimation(deltaTime);

	player1.MakeFacing(player2);
	player2.MakeFacing(player1);

	healthBarFull1.setScale(player1.GetHealth() * 0.01f, 1);
	healthBarFull2.setScale(player2.GetHealth() * 0.01f, 1);

	if (player2.GetHealth() <= 0)
		statesMachine->Change(new OverState(player1.GetName()));
	

}

void GameState::HandleEvent(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		isGameFinished = true;

	player1.PerformAttack(event, &player2);
}

void GameState::Render(sf::RenderTarget & renderTarget)
{
	renderTarget.draw(background);
	player1.Render(renderTarget);
	player2.Render(renderTarget);

	renderTarget.draw(healthBarEmpty1);
	renderTarget.draw(healthBarEmpty2);
	renderTarget.draw(healthBarFull1);
	renderTarget.draw(healthBarFull2);
}
