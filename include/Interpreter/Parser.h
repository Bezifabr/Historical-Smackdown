#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>

struct ScriptInstruction {
	std::string name;
	std::vector<std::string> arguments;

	void Clear()
	{
		name = "[EMPTY]";
		arguments.clear();
	}
};

struct ScriptObject {
	std::string type;
	std::string id;
	std::string ownedBy;
	std::queue<ScriptInstruction> instructions;

	void Clear()
	{
		type = "[EMPTY]";
		id = "[EMPTY]";
		ownedBy = "[EMPTY]";
		while (!instructions.empty())
			instructions.pop();
	}
};

class Parser {
	std::vector<std::string> instructionsAtlas;

	std::vector<ScriptObject> objects;
	std::stack<std::string> ownershipStack;

	ScriptInstruction tempInstruction;

	std::string type;
	std::string name;

	bool isTypeFound = false;
	bool isNameFound = false;
	bool isDefinitionFound = false;

	bool errorOccured = false;
	
	bool isInstructionFound = false;

	std::string errorMessage;

public:
	Parser();
	void CheckSyntax(std::string phrase);
	bool IsErrorOccurring();
	void ReturnResult();
private:
	void LookForObject(std::string phrase);

	void LookForType(std::string phrase);
	void LookForName(std::string phrase);
	void LookForDefinition(std::string phrase);

	void LookForInstruction(std::string phrase);

	bool IsSpecialCharacter(char character);

	void AddNewObject();

	ScriptObject& GetObjectById(const std::string& id);
};

#endif //!PARSER_H