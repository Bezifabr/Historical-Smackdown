#ifndef HEALTH_BAR_H
#define HEALTH_BAR_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>

class HealthBar {
	sf::Sprite full;
	sf::Sprite empty;
public:

	void LoadTextures(const sf::Texture& fullBar, const sf::Texture& emptyBar);
	void Update(int health);
	void Draw(sf::RenderTarget& renderTarget);
	void SetPosition(float x, float y);
};

#endif // !HEALTH_BAR_H
