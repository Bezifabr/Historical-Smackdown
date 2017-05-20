#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "State.h"

class GameState : public State {
	sf::Texture bgrTexture;
	sf::Texture player1Texture;
	sf::Texture player2Texture;
	sf::Sprite background;
	sf::Sprite testPlayer1;
	sf::Sprite testPlayer2;
public:

	virtual void Update();
	virtual void HandleEvent(sf::Event event);
	virtual void Render(sf::RenderTarget& renderTarget);

private:

	virtual void OnLoad();
	virtual void OnUnload();
};

#endif // !GAME_STATE_H
