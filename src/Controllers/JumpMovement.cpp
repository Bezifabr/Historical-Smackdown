#include "Controllers\JumpMovement.h"
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

void JumpMovement::SetFramesPerSeconds(int fps)
{
	this->framesPerSecond = fps;
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
		float pixelsPerFrame = velocityY / framesPerSecond;
		float displacement = pixelsPerFrame * .5f * deltaTime.asMilliseconds();
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
