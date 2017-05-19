#include "..\include\Game.h"

void Game::CreateWindow(const std::string & title)
{
	window.create(sf::VideoMode::getDesktopMode(), title);
	window.setFramerateLimit(120);
}

void Game::RunLoop()
{

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);
		window.display();

	}
}
