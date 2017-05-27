#ifndef JUMP_MOVEMENT_H
#define JUMP_MOVEMENT_H

#include "Controllers\MovementController.h"

class JumpMovement : public MovementController {
	float jumpingForce = 50;
	float gravity = 10;
	float floorLevelY = 775;
	int framesPerSecond;

	float velocityY = 0;
	bool isJumping = false;

	sf::Keyboard::Key jumpKey;
public:
	JumpMovement(float jumpingForce = 50, float gravity = 10, float floorLevelY = 775) :
		jumpingForce(jumpingForce), gravity(gravity), floorLevelY(floorLevelY) {}

	void SetJumpingForce(float jumpingForce);
	void SetGravity(float gravity);
	void SetFloorLevelY(float y);
	void SetFramesPerSeconds(int fps);

	void SetJumpKey(sf::Keyboard::Key jumpKey);

	virtual void PerformMovement(Character* jumpingCharacter, sf::Time deltaTime);
};

#endif // !JUMP_MOVEMENT_H