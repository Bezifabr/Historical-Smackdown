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
		currentState->Load();
}

void StatesMachine::Update()
{
	if (currentState)
		currentState->Update(this);
}
