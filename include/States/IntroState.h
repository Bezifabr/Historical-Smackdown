#ifndef INTRO_STATE_H
#define INTRO_STATE_H

#include "State.h"

class IntroState : public State {
public:
	virtual void Load();
	virtual void Update(StatesMachine* statesMachine);
	virtual void Unload();
};

#endif // !INTRO_STATE_H
