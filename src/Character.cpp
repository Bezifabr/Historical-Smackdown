#include "Character.h"


void Character::SetMovementController(MovementController * movementController)
{
	this->movementController = movementController;
}

void Character::PerformMovement(sf::Time deltaTime)
{
	if(movementController)
		movementController->PerformMovement(this, deltaTime);
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

sf::Vector2f Character::GetPosition()
{
	return sprite.getPosition();
}
