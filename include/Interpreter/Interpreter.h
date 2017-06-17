#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "Lexer.h"

class Interpreter {
	Lexer lexer;
	std::queue<std::string> phrasesQueue;
public:
	void LoadScriptFromFile(const char* source);
	void ShowLoadedWords();
};

#endif // !INTERPRETER_H
