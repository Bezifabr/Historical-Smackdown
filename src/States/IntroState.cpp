#include "States\IntroState.h"
#include "States\MenuState.h"
#include "StatesMachine.h"
#include <iostream>

using std::cout;
using std::endl;

void IntroState::Load()
{
	cout << "Intro loaded" << endl;
}

void IntroState::Update(StatesMachine * statesMachine)
{
	cout << "Intro updated" << endl;
	statesMachine->Change(new MenuState);
}

void IntroState::Unload()
{
	cout << "Intro unloaded" << endl;
}

void IntroState::Render(sf::RenderTarget & renderTarget)
{
	// nothing
}
