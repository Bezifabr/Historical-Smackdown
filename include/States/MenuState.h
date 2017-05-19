#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "State.h"

class MenuState : public State {
public:
	virtual void Load();
	virtual void Update(StatesMachine* statesMachine);
	virtual void Unload();
};

#endif // !MENU_STATE_H
