#include "Interpreter\ScriptObject.h"

void ScriptObject::SetType(std::string type)
{
	this->type = type;
}

void ScriptObject::SetId(std::string id)
{
	this->id = id;
}

void ScriptObject::SetOwnedBy(std::string ownedBy)
{
	this->ownedBy = ownedBy;
}

std::string ScriptObject::GetType()
{
	return this->type;
}

std::string ScriptObject::GetId()
{
	return this->id;
}

std::string ScriptObject::GetOwnedBy()
{
	return this->ownedBy;
}

void ScriptObject::AddInstruction(ScriptInstruction instruction)
{
	instructions.push(instruction);
}

ScriptObject::ScriptObject(std::string type, std::string id, std::string ownedBy)
{
	this->type = type;
	this->id = id;
	this->ownedBy = ownedBy;
}

void ScriptObject::Clear()
{
	type = "[EMPTY]";
	id = "[EMPTY]";
	ownedBy = "[EMPTY]";
	while (!instructions.empty())
		instructions.pop();
}
