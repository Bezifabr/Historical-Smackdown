#include "Character.h"

void Character::SetCharacterState(CharStateID charState)
{
	this->charStateID = charState;
}

void Character::AddAnimation(CharStateID charStateID, const Animation & animation)
{
	animations[charStateID] = animation;
}

void Character::AddMovementController(MovementController * movementController)
{
	this->movementControllers.push_back(movementController);
}

void Character::AddFightingController(FightingController * fightingController)
{
	fightingControllers.push_back(fightingController);
}

void Character::ClearMovementControllers()
{
	movementControllers.clear();
}

void Character::PerformAttack(sf::Event event, Character * target)
{
	if (!fightingControllers.empty())
		for (auto contr : fightingControllers)
			if(event.type == sf::Event::KeyPressed && event.key.code == contr->GetPunchKey())
				contr->PerformAttack(this, target);
}

void Character::PerformMovement(sf::Time deltaTime)
{
	if (!movementControllers.empty())
		for (auto movement : movementControllers)
			movement->PerformMovement(this, deltaTime);
}

void Character::PerformAnimation(sf::Time deltaTime)
{
	animationController.SetAnimation(animations[charStateID]);
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

void Character::MakeFacing(const Character & target)
{
	if (GetPosition().x > target.GetPosition().x)
	{
		sprite.setScale(-1, 1);
		sprite.setOrigin(sprite.getTextureRect().width, 0);
	}
	else if (GetPosition().x < target.GetPosition().x)
	{
		sprite.setScale(1, 1);
		sprite.setOrigin(0, 0);
	}
}

bool Character::IsCollidingWith(sf::FloatRect rect)
{
	return sprite.getGlobalBounds().intersects(rect);
}

void Character::SetHealth(int health)
{
	this->health = health;
	if (this->health <= 0)
		charStateID = CharStateID::DEAD;
}

int Character::GetHealth()
{
	return health;
}

const sf::Vector2f& Character::GetPosition() const
{
	return sprite.getPosition();
}
