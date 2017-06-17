#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "State.h"
#include "Character.h"
#include "Controllers\BasicMovement.h"
#include "Controllers\JumpMovement.h"
#include "Controllers\AnimationController.h"
#include "Controllers\PunchFighting.h"
#include "Interpreter\Interpreter.h"
#include "HealthBar.h"

class GameState : public State {
	sf::Texture bgrTexture;
	sf::Sprite background;

	Interpreter interpreter;

	PunchFighting punchFighting;
	PunchFighting punchFighting2;

	BasicMovement basicMovement;
	JumpMovement jumpMovement;
	BasicMovement basicMovement2;
	JumpMovement jumpMovement2;

	HealthBar healthBar1;
	HealthBar healthBar2;

	Character player1;
	Character player2;
public:

	virtual void HandleEvent(sf::Event event);
	virtual void Render(sf::RenderTarget& renderTarget);

private:

	virtual void OnUpdate();
	virtual void OnLoad();
	virtual void OnUnload();
};

#endif // !GAME_STATE_H
