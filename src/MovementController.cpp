#include "MovementController.h"
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


void JumpMovement::SetJumpingForce(float jumpingForce)
{
	this->jumpingForce = jumpingForce;
}

void JumpMovement::SetGravity(float gravity)
{
	this->gravity = gravity;
}

void JumpMovement::SetFloorLevelY(float y)
{
	this->floorLevelY = y;
}

void JumpMovement::SetJumpKey(sf::Keyboard::Key jumpKey)
{
	this->jumpKey = jumpKey;
}

void JumpMovement::PerformMovement(Character * jumpingCharacter, sf::Time deltaTime)
{
	sf::Vector2f position = jumpingCharacter->GetPosition();

	if (isJumping == false && sf::Keyboard::isKeyPressed(jumpKey) == true)
	{
		velocityY = jumpingForce;
		isJumping = true;
	}

	if (isJumping == true)
	{
		velocityY -= gravity;

		float displacement = velocityY * 0.01f * deltaTime.asMilliseconds();
		position.y -= displacement;
		jumpingCharacter->SetPosition(position);

		if (position.y >= floorLevelY)
		{
			isJumping = false;
			velocityY = 0;
			jumpingCharacter->SetPosition(position.x, floorLevelY);
		}
	}

}
