#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "State.h"

class GameState : public State {
public:
	virtual void OnLoad();
	virtual void Unload();

	virtual void Update();
	virtual void HandleEvent(sf::Event event);
	virtual void Render(sf::RenderTarget& renderTarget);
};

#endif // !GAME_STATE_H
