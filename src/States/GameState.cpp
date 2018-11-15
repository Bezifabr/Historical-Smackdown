#include "States/GameState.h"
#include "States/OverState.h"
#include "StatesMachine.h"

#include <iostream>

using std::cout;
using std::endl;


void GameState::OnEnter()
{
	cout << "Loading textures" << endl;
	bgrTexture.loadFromFile("resources/textures/arenas/abbacy.png");
	player1.LoadTexture("resources/textures/characters/HilterSprite.png");
	player2.LoadTexture("resources/textures/characters/SpalinSprite.png");	
	healthBar1.LoadTextures("resources/textures/GUI/Health_bar.png", "resources/textures/GUI/Health_bar_empty.png");
	healthBar2.LoadTextures("resources/textures/GUI/Health_bar.png", "resources/textures/GUI/Health_bar_empty.png");
	cout << "Loading textures done" << endl;

	background.setTexture(bgrTexture);

	cout << "Setting players" << endl;
	player1.SetPosition(50, 775);
	player2.SetPosition(775, 775);
	player1.SetName("Mr. Hilter");
	player2.SetName("Cde. Spalin");
	player1.SetHealth(100);
	player2.SetHealth(100);
	player1.SetCharacterState(CharStateID::IDLE);
	player2.SetCharacterState(CharStateID::IDLE);
	cout << "Setting players done" << endl;

	cout << "Setting players components" << endl;
	cout << "* basic movement" << endl;
	basicMovement.SetMovementSpeed(30);
	basicMovement.SetMoveLeftKey(sf::Keyboard::A);
	basicMovement.SetMoveRightKey(sf::Keyboard::D);
	basicMovement2.SetMovementSpeed(30);
	basicMovement2.SetMoveLeftKey(sf::Keyboard::Left);
	basicMovement2.SetMoveRightKey(sf::Keyboard::Right);

	cout << "* jump movement" << endl;
	jumpMovement.SetFloorLevelY(775);
	jumpMovement.SetGravity(10);
	jumpMovement.SetJumpingForce(300);
	jumpMovement.SetJumpKey(sf::Keyboard::W);
	jumpMovement2.SetFloorLevelY(775);
	jumpMovement2.SetGravity(10);
	jumpMovement2.SetJumpingForce(300);
	jumpMovement2.SetJumpKey(sf::Keyboard::Up);

	cout << "* punch fighting" << endl;
	punchSound.loadFromFile("resources/sounds/punch.wav");
	punchFighting.SetDamage(10);
	punchFighting.SetHitBox(sf::FloatRect(45, 35, 73, 65));
	punchFighting.SetKey(sf::Keyboard::G);
	punchFighting.SetAttackState(CharStateID::PUNCH);
	punchFighting.SetAttackTime(sf::seconds(.25));
	punchFighting.LoadSound(punchSound);
	punchFighting2.SetDamage(10);
	punchFighting2.SetHitBox(sf::FloatRect(100, 70, 40, 40));
	punchFighting2.SetKey(sf::Keyboard::L);
	punchFighting2.SetAttackState(CharStateID::PUNCH);
	punchFighting2.SetAttackTime(sf::seconds(.25));
	punchFighting2.LoadSound(punchSound);

	cout << "* Adding components to players" << endl;
	player1.AddMovementController(&jumpMovement);
	player1.AddMovementController(&basicMovement);
	player1.AddFightingController(&punchFighting);
	player2.AddMovementController(&jumpMovement2);
	player2.AddMovementController(&basicMovement2);
	player2.AddFightingController(&punchFighting2);
	cout << "Setting players components done" << endl;

	cout << "Setting animations" << endl;
	cout << "* Start" << endl;
	Animation stand;
	stand.AddFrame(sf::IntRect(656, 0, 164, 164));
	stand.AddFrame(sf::IntRect(656, 164, 164, 164));
	stand.SetTimeBetweenFrames(sf::seconds(0.5f));
	Animation stand2;
	stand2.AddFrame(sf::IntRect(704, 0, 176, 176));
	stand2.AddFrame(sf::IntRect(704, 176, 176, 176));
	stand2.SetTimeBetweenFrames(sf::seconds(0.5f));

	cout << "* Walk" << endl;
	Animation walk;
	walk.AddFrame(sf::IntRect(820, 0, 164, 164));
	walk.AddFrame(sf::IntRect(820, 164, 164, 164));
	walk.SetTimeBetweenFrames(sf::seconds(0.4f));
	Animation walk2;
	walk2.AddFrame(sf::IntRect(880, 0, 176, 176));
	walk2.AddFrame(sf::IntRect(880, 176, 176, 176));
	walk2.SetTimeBetweenFrames(sf::seconds(0.4f));

	cout << "* Jump" << endl;
	Animation jump;
	jump.AddFrame(sf::IntRect(164, 0, 164, 164));
	jump.AddFrame(sf::IntRect(164, 0, 164, 164));
	jump.SetTimeBetweenFrames(sf::seconds(0.01f));
	Animation jump2;
	jump2.AddFrame(sf::IntRect(176, 0, 176, 176));
	jump2.AddFrame(sf::IntRect(176, 0, 176, 176));
	jump2.SetTimeBetweenFrames(sf::seconds(0.01f));

	cout << "* Dead" << endl;
	Animation dead(stand); // temporary it has stand animation

	cout << "* Punch" << endl;
	Animation punch;
	punch.AddFrame(sf::IntRect(492, 0, 164, 164));
	punch.AddFrame(sf::IntRect(492, 0, 164, 164));
	punch.SetTimeBetweenFrames(sf::seconds(0.01f));
	Animation punch2;
	punch2.AddFrame(sf::IntRect(528, 0, 176, 176));
	punch2.AddFrame(sf::IntRect(528, 0, 176, 176));
	punch2.SetTimeBetweenFrames(sf::seconds(0.01f));

	cout << "* Adding to player 1" << endl;
	player1.AddAnimation(CharStateID::IDLE, stand);
	player1.AddAnimation(CharStateID::WALK, walk);
	player1.AddAnimation(CharStateID::JUMP, jump);
	player1.AddAnimation(CharStateID::DEAD, dead);
	player1.AddAnimation(CharStateID::PUNCH, punch);

	cout << "* Adding to player 2" << endl;
	player2.AddAnimation(CharStateID::IDLE, stand2);
	player2.AddAnimation(CharStateID::WALK, walk2);
	player2.AddAnimation(CharStateID::JUMP, jump2);
	player2.AddAnimation(CharStateID::DEAD, dead);
	player2.AddAnimation(CharStateID::PUNCH, punch2);

	cout << "Setting animations done" << endl;

	healthBar1.SetPosition(50, 50);
	healthBar2.SetPosition(700, 50);


	cout << "Game loaded" << endl;
}

void GameState::OnLeave()
{
	cout << "Game unloaded" << endl;
}

void GameState::OnUpdate()
{
	player1.PerformMovement(deltaTime);
	player2.PerformMovement(deltaTime);
	player1.PerformAnimation(deltaTime);
	player2.PerformAnimation(deltaTime);

	player1.MakeFacing(player2);
	player2.MakeFacing(player1);

	healthBar1.Update(player1.GetHealth());
	healthBar2.Update(player2.GetHealth());

	player1.EndAttack();
	player2.EndAttack();

	if (player2.GetHealth() <= 0)
		transition->Switch(std::unique_ptr<State>(new OverState(player1.GetName())));
	else if (player1.GetHealth() <= 0)
		transition->Switch(std::unique_ptr<State>(new OverState(player2.GetName())));


}

void GameState::OnHandleEvent()
{
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		isGameFinished = true;

	player1.PerformAttack(event, &player2);
	player2.PerformAttack(event, &player1);
}

void GameState::OnDraw()
{
	renderWindow->draw(background);
	player1.Render(*renderWindow);
	player2.Render(*renderWindow);

	healthBar1.Draw(*renderWindow);
	healthBar2.Draw(*renderWindow);
}
