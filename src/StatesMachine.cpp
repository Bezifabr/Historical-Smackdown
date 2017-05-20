#include "StatesMachine.h"

StatesMachine::~StatesMachine()
{
	if (currentState != nullptr)
	{
		currentState->Unload();
		delete currentState;
		currentState = nullptr;
	}
}

void StatesMachine::Change(State * state)
{
	if (currentState != nullptr)
	{
		currentState->Unload();
		delete currentState;
		currentState = nullptr;
	}

	currentState = state;

	if (currentState)
		currentState->Load(this);
}

State * StatesMachine::GetCurrentState()
{
	return currentState;
}

void StatesMachine::Update()
{
	if (currentState)
		currentState->Update();
}
