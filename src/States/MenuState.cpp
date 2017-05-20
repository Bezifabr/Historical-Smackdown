#include "States\MenuState.h"
#include "States\LobbyState.h"
#include "StatesMachine.h"
#include <iostream>

using std::cout;
using std::endl;

void MenuState::OnLoad()
{
	cout << "Menu loaded" << endl;

	playTexture.loadFromFile("resources/textures/menu/play.png");
	statsTexture.loadFromFile("resources/textures/menu/stats.png");
	exitTexture.loadFromFile("resources/textures/menu/exit.png");
	menu.AddOption("Play");
	menu.AddOption("Stats");
	menu.AddOption("Exit");

}

void MenuState::OnUnload()
{
	menu.ClearOptions();
	cout << "Menu unloaded" << endl;
}

void MenuState::Update()
{
	std::string option = menu.GetCurrentOption();

	if (option == "Play")
		sprite.setTexture(playTexture);
	if (option == "Stats")
		sprite.setTexture(statsTexture);
	if (option == "Exit")
		sprite.setTexture(exitTexture);
}

void MenuState::HandleEvent(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Escape)
			isGameFinished = true;

		else if (event.key.code == sf::Keyboard::Up)
			menu.Previous();

		else if (event.key.code == sf::Keyboard::Down)
			menu.Next();

		else if (event.key.code == sf::Keyboard::Return)
			ProceedMenuOption();
	}
}

void MenuState::Render(sf::RenderTarget & renderTarget)
{
	renderTarget.draw(sprite);
}

void MenuState::ProceedMenuOption()
{
	std::string option = menu.GetCurrentOption();

	if (option == "Play")
		statesMachine->Change(new LobbyState);
	if (option == "Stats")
	{
		// TODO: Add stats state
	}
	if (option == "Exit")
		isGameFinished = true;

}
