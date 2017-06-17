#include "Interpreter\Interpreter.h"
#include <fstream>
#include <iostream>

void Interpreter::LoadScriptFromFile(const char * source)
{
	std::fstream file;
	file.open(source, std::ios::in | std::ios::out);

	if (file.good())
	{
		std::string line;
		while (!file.eof())
		{
			std::getline(file, line);
			auto queue = lexer.FindPhrases(line);

			while (!queue.empty())
			{
				phrasesQueue.push(queue.front());
				queue.pop();
			}
		}
		file.close();
	}
}

void Interpreter::ShowLoadedWords()
{
	while (!phrasesQueue.empty())
	{
		std::cout << phrasesQueue.front() << std::endl;
		phrasesQueue.pop();
	}
}
