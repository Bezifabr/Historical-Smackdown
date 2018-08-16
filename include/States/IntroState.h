#ifndef INTRO_STATE_H
#define INTRO_STATE_H

#include "State.h"

class IntroState : public State {
public:

	virtual void HandleEvent(sf::Event event);
	virtual void Render(sf::RenderTarget& renderTarget);

private:

	virtual void OnUpdate();
	virtual void OnLoad();
	virtual void OnUnload();
};

#endif // !INTRO_STATE_H
