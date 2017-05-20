#include "State.h"

void State::Load(StatesMachine * statesMachine)
{
	this->statesMachine = statesMachine;
	OnLoad();
}

bool State::IsGameFinished()
{
	return isGameFinished;
}
