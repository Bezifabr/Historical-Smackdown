#include "Controllers/JumpMovement.h"
#include "Character.h"

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
		jumpingCharacter->SetCharacterState(CharStateID::JUMP);

		velocityY -= gravity;
		float displacement = velocityY / 200;
		position.y -= displacement * deltaTime.asMilliseconds();
		jumpingCharacter->SetPosition(position);

		if (position.y >= floorLevelY)
		{
			isJumping = false;
			velocityY = 0;
			jumpingCharacter->SetPosition(position.x, floorLevelY);
			jumpingCharacter->SetCharacterState(CharStateID::IDLE);
		}
	}

}
