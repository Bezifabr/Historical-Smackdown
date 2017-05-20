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

	sf::Keyboard::Key jumpKey;
	sf::Keyboard::Key moveLeftKey;
	sf::Keyboard::Key moveRightKey;
public:
	BasicMovement(float movementSpeed = 0) : movementSpeed(movementSpeed) {}

	void SetMovementSpeed(float movementSpeed);

	void SetJumpKey(sf::Keyboard::Key jumpKey);
	void SetMoveLeftKey(sf::Keyboard::Key moveLeftKey);
	void SetMoveRightKey(sf::Keyboard::Key moveRightKey);

	virtual void PerformMovement(Character* movingCharacter, sf::Time deltaTime);
};

#endif // !MOVEMENT_CONTROLLER_H
