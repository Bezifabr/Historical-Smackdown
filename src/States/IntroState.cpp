#include "States/IntroState.h"
#include "States/MenuState.h"
#include "StatesMachine.h"
#include <iostream>

using std::cout;
using std::endl;

void IntroState::OnLoad()
{
	cout << "Intro loaded" << endl;
}

void IntroState::OnUnload()
{
	cout << "Intro unloaded" << endl;
}

void IntroState::OnUpdate()
{
	cout << "Intro updated" << endl;
	statesMachine->Change(new MenuState);
}

void IntroState::HandleEvent(sf::Event event)
{
	// nothing
}

void IntroState::Render(sf::RenderTarget & renderTarget)
{
	// nothing
}
