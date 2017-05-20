#ifndef MOVEMENT_CONTROLLER_H
#define MOVEMENT_CONTROLLER_H

#include <SFML/Window/Event.hpp>

class Character;

class MovementController {
public:
	virtual void PerformMovement(Character* movingCharacter, sf::Time deltaTime) = 0;

};

class BasicMovement : public MovementController {
	float movementSpeed = 0;

	sf::Keyboard::Key moveLeftKey;
	sf::Keyboard::Key moveRightKey;
public:
	BasicMovement(float movementSpeed = 0) : movementSpeed(movementSpeed) {}

	void SetMovementSpeed(float movementSpeed);

	void SetMoveLeftKey(sf::Keyboard::Key moveLeftKey);
	void SetMoveRightKey(sf::Keyboard::Key moveRightKey);

	virtual void PerformMovement(Character* movingCharacter, sf::Time deltaTime);
};

class JumpMovement : public MovementController {
	float jumpingForce = 50;
	float gravity = 10;
	float floorLevelY = 775;

	float velocityY = 0;
	bool isJumping = false;

	sf::Keyboard::Key jumpKey;
public:
	JumpMovement(float jumpingForce = 50, float gravity = 10, float floorLevelY = 775) :
		jumpingForce(jumpingForce), gravity(gravity), floorLevelY(floorLevelY) {}

	void SetJumpingForce(float jumpingForce);
	void SetGravity(float gravity);
	void SetFloorLevelY(float y);

	void SetJumpKey(sf::Keyboard::Key jumpKey);

	virtual void PerformMovement(Character* jumpingCharacter, sf::Time deltaTime);
};

#endif // !MOVEMENT_CONTROLLER_H
