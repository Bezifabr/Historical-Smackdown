#include "States/MenuState.h"
#include "States/LobbyState.h"
#include "StatesMachine.h"
#include <iostream>

using std::cout;
using std::endl;


void MenuState::OnEnter()
{
	cout << "Menu loaded" << endl;

	playTexture.loadFromFile("resources/textures/menu/play.png");
	statsTexture.loadFromFile("resources/textures/menu/stats.png");
	exitTexture.loadFromFile("resources/textures/menu/exit.png");
	menu.AddOption("Play");
	menu.AddOption("Stats");
	menu.AddOption("Exit");
}

void MenuState::OnLeave()
{
	menu.ClearOptions();
	cout << "Menu unloaded" << endl;
}

void MenuState::OnUpdate()
{
	std::string option = menu.GetCurrentOption();
	if (option == "Play")
		sprite.setTexture(playTexture);
	if (option == "Stats")
		sprite.setTexture(statsTexture);
	if (option == "Exit")
		sprite.setTexture(exitTexture);
}

void MenuState::OnDraw()
{
	renderWindow->draw(sprite);
}

void MenuState::OnHandleEvent()
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


void MenuState::ProceedMenuOption()
{
	std::string option = menu.GetCurrentOption();

	if (option == "Play")
		transition->Switch(std::unique_ptr<State>(new LobbyState));
	if (option == "Stats")
	{
		// TODO: Add stats state
	}
	if (option == "Exit")
		isGameFinished = true;

}
