#include "Character.h"


void Character::AddMovementController(MovementController * movementController)
{
	this->movementControllers.push_back(movementController);
}

void Character::ClearMovementControllers()
{
	movementControllers.clear();
}

void Character::PerformMovement(sf::Time deltaTime)
{
	if (!movementControllers.empty())
		for (auto movement : movementControllers)
			movement->PerformMovement(this, deltaTime);
}

void Character::PerformAnimation(sf::Time deltaTime)
{
	animationController.PerformAnimation(sprite, deltaTime);
}

void Character::LoadTexture(const std::string & filename)
{
	texture.loadFromFile(filename);
	sprite.setTexture(texture);
}

void Character::Render(sf::RenderTarget & renderTarget)
{
	renderTarget.draw(sprite);
}

void Character::SetName(const std::string & name)
{
	this->name = name;
}

const std::string & Character::GetName()
{
	return name;
}

void Character::SetPosition(sf::Vector2f position)
{
	sprite.setPosition(position);
}

void Character::SetPosition(float x, float y)
{
	SetPosition(sf::Vector2f(x, y));
}

void Character::TurnLeft()
{
	sprite.setScale(-1, 1);
	sprite.setOrigin(sprite.getTextureRect().width, 0);
}

void Character::TurnRight()
{
	sprite.setScale(1, 1);
	sprite.setOrigin(0, 0);
}

void Character::SetAnimation(const Animation & animation)
{
	animationController.SetAnimation(animation);
}

sf::Vector2f Character::GetPosition()
{
	return sprite.getPosition();
}
