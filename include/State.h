#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "TexturesHolder.h"

class StateTransition;
class State {
public:
    void ConnectWithStateTransition(StateTransition* transition);
	void ConnectWithRenderWindow(std::shared_ptr<sf::RenderWindow> renderWindow);

	bool IsGameFinished();

    virtual void OnEnter() = 0;
    virtual void OnLeave() = 0;
    virtual void OnShow() {}
    virtual void OnHide() {}

	void HandleEvent(sf::Event event);
	void Update(sf::Time deltaTime);
	void Draw();

protected:
    StateTransition* transition;
	std::shared_ptr<sf::RenderWindow> renderWindow;
	TexturesHolder textures;

	bool isGameFinished = false;

	sf::Time deltaTime;
	sf::Event event;

	virtual void OnHandleEvent() {}
    virtual void OnUpdate() = 0;
	virtual void OnDraw() {}
};

#endif // !STATE_H
