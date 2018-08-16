#include "HealthBar.h"


void HealthBar::LoadTextures(const std::string & full, const std::string & empty)
{
	fullTexture.loadFromFile(full);
	emptyTexture.loadFromFile(empty);
	this->full.setTexture(fullTexture);
	this->empty.setTexture(emptyTexture);
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
