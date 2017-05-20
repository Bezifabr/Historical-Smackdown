#ifndef BASIC_MOVEMENT_H
#define BASIC_MOVEMENT_H

#include "Controllers\MovementController.h"

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

#endif // !BASIC_MOVEMENT_H