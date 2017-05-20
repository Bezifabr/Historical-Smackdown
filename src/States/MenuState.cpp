#include "States\MenuState.h"
#include <iostream>

using std::cout;
using std::endl;

void MenuState::Load()
{
	cout << "Menu loaded" << endl;

	playTexture.loadFromFile("resources/textures/menu/play.png");
	statsTexture.loadFromFile("resources/textures/menu/stats.png");
	exitTexture.loadFromFile("resources/textures/menu/exit.png");

	option = 0;
}

void MenuState::Update(StatesMachine * statesMachine)
{
	switch (option)
	{
	case 0:
	{
		sprite.setTexture(playTexture);
		break;
	}
	case 1:
	{
		sprite.setTexture(statsTexture);
		break;
	}
	case 2:
	{
		sprite.setTexture(exitTexture);
		break;
	}
	default:
		break;
	}
}

void MenuState::Unload()
{
	cout << "Menu unloaded" << endl;
}

void MenuState::HandleEvent(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if(event.key.code == sf::Keyboard::Escape)
			isGameFinished = true;

		else if (event.key.code == sf::Keyboard::Up)
		{
			if (option > 0)
				option--;
			else
				option = 2;
		}
		else if (event.key.code == sf::Keyboard::Down)
		{
			if (option < 2)
				option++;
			else
				option = 0;
		}
	}
}

void MenuState::Render(sf::RenderTarget & renderTarget)
{
	renderTarget.draw(sprite);
}
