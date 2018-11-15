#include "States/MenuState.h"
#include "States/LobbyState.h"
#include "StatesMachine.h"
#include <iostream>

using std::cout;
using std::endl;


void MenuState::OnEnter()
{
	cout << "Menu loaded" << endl;

	textures.Load("play", "menu/play");
	textures.Load("stats", "menu/stats");
	textures.Load("exit", "menu/exit");
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
		sprite.setTexture(textures.GetTexture("play"));
	if (option == "Stats")
		sprite.setTexture(textures.GetTexture("stats"));
	if (option == "Exit")
		sprite.setTexture(textures.GetTexture("exit"));
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
