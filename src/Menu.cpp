#include "Menu.h"

void Menu::AddOption(const std::string & option)
{
	options.push_back(option);
}

void Menu::Next()
{
	if (currentOption < options.size() - 1)
		currentOption++;
	else
		currentOption = 0;
}

void Menu::Previous()
{
	if (currentOption > 0)
		currentOption--;
	else
		currentOption = options.size() - 1;
}

const std::string & Menu::GetCurrentOption()
{
	return options[currentOption];
}

void Menu::ClearOptions()
{
	options.clear();
}
