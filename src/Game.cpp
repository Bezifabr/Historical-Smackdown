#include "Game.h"

void Game::CreateWindow(const std::string & title)
{
	window.create(sf::VideoMode::getDesktopMode(), title);
	window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(false);
}

void Game::Initialize(State * initState)
{
	statesMachine.Change(initState);
}

void Game::RunLoop()
{
	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Time deltaTime = clock.restart();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			statesMachine.GetCurrentState()->HandleEvent(event);
		}

		statesMachine.Update(deltaTime);
		window.clear(sf::Color::White);
		statesMachine.GetCurrentState()->Render(window);
		window.display();


		if (statesMachine.GetCurrentState()->IsGameFinished())
			window.close();

	}
}
