#ifndef ANIMATION_CONTROLLER_H
#define ANIMATION_CONTROLLER_H

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>
#include <vector>


class Animation {
	std::vector<sf::IntRect> frames;
	sf::Time time;
public:
	Animation(sf::Time timeBetweenFrames = sf::seconds(0.2f));

	void AddFrame(const sf::IntRect& frameRect);
	void SetTimeBetweenFrames(sf::Time timeBetweenFrames);

	const sf::IntRect& GetFrame(size_t n) const;
	const sf::Time& GetTimeBetweenFrames() const;
	size_t GetSize() const;
};


class AnimationController {
	const Animation* currentAnimation;
	sf::Time currentTime;
	std::size_t currentFrame = 0;
public:
	AnimationController(sf::Time currentTime = sf::seconds(0), std::size_t currentFrame = 0);

	void SetAnimation(const Animation& animation);
	void PerformAnimation(sf::Sprite& sprite, sf::Time deltaTime);
};


#endif // !ANIMATION_CONTROLLER_H
