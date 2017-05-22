#include "HealthBar.h"


void HealthBar::LoadTextures(const std::string & full, const std::string & empty)
{
	fullTexture.loadFromFile(full);
	emptyTexture.loadFromFile(empty);
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
