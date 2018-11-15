#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "State.h"
#include "Character.h"
#include "Controllers/BasicMovement.h"
#include "Controllers/JumpMovement.h"
#include "Controllers/AnimationController.h"
#include "Controllers/PunchFighting.h"
#include "Interpreter/Interpreter.h"
#include "HealthBar.h"
#include <SFML/Audio.hpp>

class GameState : public State {
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

	sf::SoundBuffer punchSound;
private:

	virtual void OnHandleEvent() override;
	virtual void OnDraw() override;

	virtual void OnUpdate() override;

	virtual void OnEnter() override;
	virtual void OnLeave() override;
};

#endif // !GAME_STATE_H
