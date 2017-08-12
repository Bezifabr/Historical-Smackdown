#include "Interpreter\Parser.h"
#include <iostream>
#include <Windows.h>

Parser::Parser()
{
	ScriptObject emptyObject;
	emptyObject.id = "[EMPTY]";
	emptyObject.ownedBy = "[EMPTY]";
	emptyObject.type = "[EMPTY]";
	objects.push_back(emptyObject);

	ownershipStack.push("[MAIN]");

	instructionsAtlas.push_back("SetName");
	instructionsAtlas.push_back("LoadTexture");
	instructionsAtlas.push_back("SetStates");
	instructionsAtlas.push_back("SetState");
	instructionsAtlas.push_back("AddFrame");
	instructionsAtlas.push_back("SetTimeBetweenFrames");
	instructionsAtlas.push_back("SetDamage");
	instructionsAtlas.push_back("SetHitbox");
	instructionsAtlas.push_back("SetKey");
	instructionsAtlas.push_back("SetAttackTime");
	instructionsAtlas.push_back("SetSound");
	instructionsAtlas.push_back("SetSpeed");
	instructionsAtlas.push_back("SetLeftKey");
	instructionsAtlas.push_back("SetRightKey");
	instructionsAtlas.push_back("SetFloorLevel");
	instructionsAtlas.push_back("SetGravity");
	instructionsAtlas.push_back("SetForce");
}

void Parser::CheckSyntax(std::string phrase)
{
		LookForObject(phrase);
		if (phrase == "}")
			if(!ownershipStack.empty())
				ownershipStack.pop();
			else
			{
				errorOccured = true;
				errorMessage = "[PARSER] Illegal usage of '}'";
			}
		else if (isInstructionFound == false)
			LookForInstruction(phrase);
		else if (phrase != ")" && phrase != "(" && phrase != ",")
			tempInstruction.arguments.push_back(phrase);
		else if (phrase == ")")
		{

			HANDLE hConsole;
			hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 8);

			std::cout << tempInstruction.name;
			for (auto arg : tempInstruction.arguments)
				std::cout << " " << arg;
			std::cout << std::endl;

			SetConsoleTextAttribute(hConsole, 7);

			isInstructionFound = false;
			GetObjectById(ownershipStack.top()).instructions.push(tempInstruction);
			tempInstruction.Clear();
		}
}

bool Parser::IsErrorOccurring()
{
	return errorOccured;
}

void Parser::ReturnResult()
{

	if (errorOccured)
	{
		HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(hConsole, 12);

		std::cout << errorMessage << std::endl;

		SetConsoleTextAttribute(hConsole, 7);
	}
	else
		std::cout << "[PARSER] Loading complete!" << std::endl;
}

void Parser::LookForObject(std::string phrase)
{
	if (isTypeFound == false)
		LookForType(phrase);
	else if (isNameFound == false)
		LookForName(phrase);
	else if (isDefinitionFound == false)
		LookForDefinition(phrase);
	else
	{
		AddNewObject();
		isTypeFound = false;
		isNameFound = false;
		isDefinitionFound = false;
	}
}

void Parser::LookForInstruction(std::string phrase)
{
	if(!instructionsAtlas.empty())
	for (auto instruction : instructionsAtlas)
		if (phrase == instruction)
		{
			tempInstruction.name = instruction;
			isInstructionFound = true;
		}
}

void Parser::LookForType(std::string phrase)
{
	isTypeFound = true;
	if (phrase == "CHARACTER" || phrase == "character" || phrase == "Character")
		type = "CHARACTER";
	else if (phrase == "ANIMATION" || phrase == "animation" || phrase == "Animation")
		type = "ANIMATION";
	else if (phrase == "COMPONENT" || phrase == "component" || phrase == "Component")
		type = "COMPONENT";
	else
	{
		isTypeFound = false;
	}
}

void Parser::LookForName(std::string phrase)
{
	isNameFound = true;
	for (auto character : phrase)
		if (IsSpecialCharacter(character))
			isNameFound = false;

	if (isNameFound)
		name = phrase;
	else
	{
		errorMessage = "[PARSER ERROR] Illegal name '" + phrase + "'.";
		errorOccured = true;
	}
}

void Parser::LookForDefinition(std::string phrase)
{
	if (phrase == "{")
		isDefinitionFound = true;
	else
	{
		errorMessage = "[PARSER ERROR] Definition not found.";
		errorOccured = true;
	}
}

bool Parser::IsSpecialCharacter(char character)
{
	return character == ' ' || character == '	' || character == '{' ||
		character == '(' || character == '"' || character == ';' ||
		character == ')' || character == '}' || character == ',' ||
		character == '.' || character == '=';
}

void Parser::AddNewObject()
{
	ScriptObject tempObject;
	tempObject.type = type;
	tempObject.id = name;
	tempObject.ownedBy = ownershipStack.top();
	ownershipStack.push(name);
	objects.push_back(tempObject);
}

ScriptObject & Parser::GetObjectById(const std::string & id)
{
	if(!objects.empty())
	for (auto itr = objects.begin(); itr != objects.end(); itr++)
		if (itr->id == id)
			return (*itr);
	return objects[0];
}
