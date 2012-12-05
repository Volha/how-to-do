#pragma once
#include <string>
#include <vector>
#include <map>
class Dictinary
{
public:
	enum SimpleCommands {ADD, DOT, MOD, FOURTHTO1, THIRDTO1, MULT, DUP, COLON, RUNTHREAD};
	typedef std::map<std::string, std::vector<SimpleCommands>> DictinaryType;

	static Dictinary* Instance();
	~Dictinary();
	void AddOperationToDict(const std::string& name, std::vector<SimpleCommands>&& params);
	void AddNewOperation(const std::vector<std::string> tokens);
	const DictinaryType* GetDictinary() const;
	std::vector<SimpleCommands> Arguments(size_t n,...);
private:
	Dictinary();
private:
	static Dictinary* s_instance;
	DictinaryType m_dictinary;
};