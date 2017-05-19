#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include "State.h"

class StatesMachine {
	State* currentState = nullptr;
public:
	~StatesMachine();

	void Change(State* state);
	State* GetCurrentState();
	void Update();
};

#endif // !STATE_MACHINE_H
