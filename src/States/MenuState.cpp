#include "States\MenuState.h"
#include <iostream>

using std::cout;
using std::endl;

void MenuState::Load()
{
	cout << "Menu loaded" << endl;
	texture.loadFromFile("resources/test/greenorb.png");
	sprite.setTexture(texture);
}

void MenuState::Update(StatesMachine * statesMachine)
{
	
}

void MenuState::Unload()
{
	cout << "Menu unloaded" << endl;
}

void MenuState::Render(sf::RenderTarget & renderTarget)
{
	renderTarget.draw(sprite);
}
