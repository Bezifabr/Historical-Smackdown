#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "State.h"
#include "Character.h"

class GameState : public State {
	sf::Texture bgrTexture;
	sf::Sprite background;

	Character player1;
	Character player2;
public:

	virtual void Update();
	virtual void HandleEvent(sf::Event event);
	virtual void Render(sf::RenderTarget& renderTarget);

private:

	virtual void OnLoad();
	virtual void OnUnload();
};

#endif // !GAME_STATE_H
