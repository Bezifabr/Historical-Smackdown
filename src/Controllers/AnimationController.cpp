#include "Controllers\AnimationController.h"

Animation::Animation(sf::Time timeBetweenFrames)
{
	this->time = timeBetweenFrames;
}

void Animation::AddFrame(const sf::IntRect & frameRect)
{
	frames.push_back(frameRect);
}

const sf::IntRect & Animation::GetFrame(size_t n) const
{
	return frames[n];
}

size_t Animation::GetSize() const
{
	return frames.size();
}

void Animation::SetTimeBetweenFrames(sf::Time timeBetweenFrames)
{
	this->time = timeBetweenFrames;
}

const sf::Time& Animation::GetTimeBetweenFrames() const
{
	return this->time;
}



AnimationController::AnimationController(sf::Time currentTime, std::size_t currentFrame)
{
	this->currentTime = currentTime;
	this->currentFrame = currentFrame;
}

void AnimationController::SetAnimation(const Animation & animation)
{
	this->currentAnimation = &animation;
}

void AnimationController::PerformAnimation(sf::Sprite & sprite, sf::Time deltaTime)
{
	if (currentAnimation)
	{
		currentTime += deltaTime;
		if (currentTime > currentAnimation->GetTimeBetweenFrames())
		{
			currentTime = sf::microseconds(currentTime.asMicroseconds() % currentAnimation->GetTimeBetweenFrames().asMicroseconds());

			if (currentFrame + 1 < currentAnimation->GetSize())
				currentFrame++;
			else
				currentFrame = 0;
		}

		sprite.setTextureRect(currentAnimation->GetFrame(currentFrame));

	}
}
