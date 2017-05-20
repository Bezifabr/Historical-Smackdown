#include "Controllers\BasicMovement.h"
#include "Character.h"

void BasicMovement::SetMovementSpeed(float movementSpeed)
{
	this->movementSpeed = movementSpeed;
}

void BasicMovement::SetMoveLeftKey(sf::Keyboard::Key moveLeftKey)
{
	this->moveLeftKey = moveLeftKey;
}

void BasicMovement::SetMoveRightKey(sf::Keyboard::Key moveRightKey)
{
	this->moveRightKey = moveRightKey;
}

void BasicMovement::PerformMovement(Character * movingCharacter, sf::Time deltaTime)
{
	sf::Vector2f position = movingCharacter->GetPosition();
	float displacement = movementSpeed * 0.01f * deltaTime.asMilliseconds();

	if (sf::Keyboard::isKeyPressed(moveLeftKey) == true)
		position.x -= displacement;
	if (sf::Keyboard::isKeyPressed(moveRightKey) == true)
		position.x += displacement;

	movingCharacter->SetPosition(position);
}
