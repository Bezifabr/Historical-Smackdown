#include <string>
#include <queue>
#include "ScriptInstruction.h"

class ScriptObject {

	std::string type;
	std::string id;
	std::string ownedBy;
	std::queue<ScriptInstruction> instructions;

public:
	ScriptObject(std::string type, std::string id, std::string ownedBy);

	void SetType(std::string type);
	void SetId(std::string id);
	void SetOwnedBy(std::string ownedBy);

	std::string GetType();
	std::string GetId();
	std::string GetOwnedBy();

	void AddInstruction(ScriptInstruction instruction);

	void Clear();
};