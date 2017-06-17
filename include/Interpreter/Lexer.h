#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <queue>

class Lexer {
public:
	std::queue<std::string> FindPhrases(std::string line);
private:
	bool IsSpecialCharacter(char character);
};

#endif // !LEXER_H
