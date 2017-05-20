#include "States\GameState.h"
#include "StatesMachine.h"

#include <iostream>

using std::cout;
using std::endl;

void GameState::OnLoad()
{
	bgrTexture.loadFromFile("resources/textures/arenas/abbacy.png");
	background.setTexture(bgrTexture);

	player1Texture.loadFromFile("resources/textures/characters/hilter.png");
	player2Texture.loadFromFile("resources/textures/characters/spalin.png");

	testPlayer1.setTexture(player1Texture);
	testPlayer2.setTexture(player2Texture);

	testPlayer1.setPosition(50, 775);
	testPlayer2.setPosition(1000, 775);
	testPlayer2.setScale(-1, 1);

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
	renderTarget.draw(background);
	renderTarget.draw(testPlayer1);
	renderTarget.draw(testPlayer2);
}
