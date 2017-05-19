#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include "State.h"

class StatesMachine {
	State* currentState = nullptr;
public:
	~StatesMachine();

	void Change(State* state);
	void Update();
};

#endif // !STATE_MACHINE_H
