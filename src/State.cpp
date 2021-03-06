#include "State.h"
#include <stdexcept>

void State::ConnectWithStateTransition(StateTransition* transition)
{
	this->transition = transition;
}

void State::ConnectWithRenderWindow(std::shared_ptr<sf::RenderWindow> renderWindow)
{
	this->renderWindow = renderWindow;
}

void State::HandleEvent(sf::Event event)
{
	this->event = event;
	OnHandleEvent();
}

void State::Update(sf::Time deltaTime)
{
	if (!transition) throw std::runtime_error("Cannot find StateTransition object");
	if (!renderWindow) throw std::runtime_error("Cannot find sf::RenderWindow object");

	this->deltaTime = deltaTime;
	OnUpdate();
}

void State::Draw()
{
	OnDraw();
}

bool State::IsGameFinished()
{
	return isGameFinished;
}
