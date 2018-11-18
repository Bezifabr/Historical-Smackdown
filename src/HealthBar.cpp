#include "HealthBar.h"


void HealthBar::LoadTextures(const sf::Texture& fullBar, const sf::Texture& emptyBar)
{
	this->full.setTexture(fullBar);
	this->empty.setTexture(emptyBar);
}

void HealthBar::Update(int health)
{
	full.setScale(health * 0.01f, 1);
}

void HealthBar::Draw(sf::RenderTarget & renderTarget)
{
	renderTarget.draw(empty);
	renderTarget.draw(full);
}

void HealthBar::SetPosition(float x, float y)
{
	full.setPosition(x, y);
	empty.setPosition(x, y);
}
