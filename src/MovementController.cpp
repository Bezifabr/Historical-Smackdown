#include "MovementController.h"
#include "Character.h"

void BasicMovement::SetMovementSpeed(float movementSpeed)
{
	this->movementSpeed = movementSpeed;
}

void BasicMovement::SetJumpKey(sf::Keyboard::Key jumpKey)
{
	this->jumpKey = jumpKey;
}

void BasicMovement::SetMoveLeftKey(sf::Keyboard::Key moveLeftKey)
{
	this->moveLeftKey = moveLeftKey;
}

void BasicMovement::SetMoveRightKey(sf::Keyboard::Key moveRightKey)
{
	this->moveRightKey = moveRightKey;
}

void BasicMovement::PerformMovement(Character * movingCharacter)
{
	sf::Vector2f position = movingCharacter->GetPosition();

	if (sf::Keyboard::isKeyPressed(moveLeftKey) == true)
		position.x -= movementSpeed;
	if (sf::Keyboard::isKeyPressed(moveRightKey) == true)
		position.x += movementSpeed;

	// Jump is temporarily unavailable


	movingCharacter->SetPosition(position);
}
