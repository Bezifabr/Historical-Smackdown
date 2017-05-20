#ifndef LOBBY_STATE_H
#define LOBBY_STATE_H

#include "State.h"

class LobbyState : public State {
public:
	virtual void OnLoad();
	virtual void Unload();

	virtual void Update();
	virtual void HandleEvent(sf::Event event);
	virtual void Render(sf::RenderTarget& renderTarget);
};

#endif // !LOBBY_STATE_H
