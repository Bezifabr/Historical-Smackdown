#include "Controllers/PunchFighting.h"
#include "Character.h"

void PunchFighting::SetDamage(float damage)
{
	this->damage = damage;
}

void PunchFighting::SetHitBox(sf::FloatRect rect)
{
	hitBox.setSize(sf::Vector2f(rect.width, rect.height));
	hitBoxPosition = sf::Vector2f(rect.left, rect.top);
}

void PunchFighting::PerformAttack(Character * attacker, Character * target)
{
	sf::Vector2f position = attacker->GetPosition() + hitBoxPosition;
	hitBox.setPosition(position);
	if (target->IsCollidingWith(hitBox.getGlobalBounds()))
	{
		PlaySound();
		int health = target->GetHealth();
		health -= damage;
		target->SetHealth(health);
	}
}
