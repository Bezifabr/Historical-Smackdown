#include "Interpreter/Parser.h"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <algorithm>
#include <vector>

Parser::Parser()
{
	ScriptObject emptyObject("[EMPTY]", "[EMPTY]", "[EMPTY]");
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
	instructionsAtlas.push_back("AddComponent");
}

void Parser::CheckSyntax(std::string phrase)
{
		FindObject(phrase);
		if (phrase == "}")
			if(!ownershipStack.empty())
				ownershipStack.pop();
			else
			{
				errorOccured = true;
				errorMessage = "[PARSER] Illegal usage of '}'";
			}
		else if (isInstructionFound == false)
			FindInstruction(phrase);
		else if (phrase != ")" && phrase != "(" && phrase != ",")
			tempInstruction.AddArgument(phrase);
		else if (phrase == ")")
		{

			std::cout << tempInstruction.GetName();
			for (auto itr = tempInstruction.GetArgumentsBegin(); itr != tempInstruction.GetArgumentsEnd(); itr++)
				std::cout << " " << *itr;
			std::cout << std::endl;

			isInstructionFound = false;
			GetObjectById(ownershipStack.top()).AddInstruction(tempInstruction);
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
		std::cout << errorMessage << std::endl;
	}
	else
		std::cout << "[PARSER] Loading complete!" << std::endl;
}

void Parser::FindObject(std::string phrase)
{
	if (isTypeFound == false)
		FindType(phrase);
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

		std::cout << objects[objects.size() - 1].GetType() << " " << objects[objects.size() - 1].GetId() << std::endl;

	}
}

void Parser::FindInstruction(std::string phrase)
{
	if(!instructionsAtlas.empty())
	for (auto instruction : instructionsAtlas)
		if (phrase == instruction)
		{
			tempInstruction.SetName(instruction);
			isInstructionFound = true;
		}
}

void Parser::FindType(std::string phrase)
{
	isTypeFound = true;
	if (boost::iequals(phrase, "Character"))
		type = "CHARACTER";
	else if (boost::iequals(phrase, "Animation"))
		type = "ANIMATION";
	else if (boost::iequals(phrase, "Component"))
		type = "COMPONENT";
	else
		isTypeFound = false;
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
	std::vector<char> charactersArray = { ' ', '\t', '{', '}', '(', ')', '"', ';', ',', '.', '=' };
	return std::any_of(charactersArray.begin(), charactersArray.end(), [character](char c){ return character == c; });
}

void Parser::AddNewObject()
{
	ScriptObject tempObject(type, name, ownershipStack.top());
	ownershipStack.push(name);
	objects.push_back(tempObject);
}

ScriptObject & Parser::GetObjectById(const std::string & id)
{
	if(!objects.empty())
	for (auto itr = objects.begin(); itr != objects.end(); itr++)
		if (itr->GetId() == id)
			return (*itr);
	return objects[0];
}
