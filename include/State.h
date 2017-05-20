#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>

class StatesMachine;
class State {
public:
	virtual void Load() = 0;
	virtual void Update(StatesMachine* stateMachine) = 0;
	virtual void Unload() = 0;

	virtual void HandleEvent(sf::Event event) = 0;
	virtual void Render(sf::RenderTarget& renderTarget) = 0;

	bool IsGameFinished();
protected:
	bool isGameFinished = false;
};

#endif // !STATE_H
