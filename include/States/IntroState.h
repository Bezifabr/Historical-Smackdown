#ifndef INTRO_STATE_H
#define INTRO_STATE_H

#include "State.h"

class IntroState : public State {
public:
	virtual void Load();
	virtual void Update(StatesMachine* statesMachine);
	virtual void Unload();

	virtual void HandleEvent(sf::Event event);
	virtual void Render(sf::RenderTarget& renderTarget);
};

#endif // !INTRO_STATE_H
