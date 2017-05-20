#include "State.h"

void State::Load(StatesMachine * statesMachine)
{
	this->statesMachine = statesMachine;
	OnLoad();
}

void State::Unload()
{
	statesMachine = nullptr;
	OnUnload();
}

bool State::IsGameFinished()
{
	return isGameFinished;
}
