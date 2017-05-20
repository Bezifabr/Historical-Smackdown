#ifndef MENU_H
#define MENU_H

#include  <vector>

class Menu {
	std::vector<std::string> options;
	size_t currentOption = 0;
public:
	void AddOption(const std::string& option);

	void Next();
	void Previous();

	const std::string& GetCurrentOption();

	void ClearOptions();
};

#endif // !MENU_H