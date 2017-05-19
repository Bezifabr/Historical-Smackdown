#include "States\MenuState.h"
#include <iostream>

using std::cout;
using std::endl;

void MenuState::Load()
{
	cout << "Menu loaded" << endl;
}

void MenuState::Update(StatesMachine * statesMachine)
{
	cout << "Menu updated" << endl;
}

void MenuState::Unload()
{
	cout << "Menu unloaded" << endl;
}
