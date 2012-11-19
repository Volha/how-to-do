#pragma once
#include <string>
#include <map>
#include <vector>

class InterpreterClass
{
	class Operation;
	typedef std::map<std::string, Operation> MapType;
	enum TypesEnum {STRING, INT};
public:
	InterpreterClass();
	~InterpreterClass();
	MapType* InitializeMap();
	void RunCommand(const std::string& commandLine);

private:
	void Print(const std::string& params = "");
	void Decorate(const std::string& params = "");
	void Sum(const std::string& params = "");


	void AddOperation(const std::string& operationName, const Operation& operation);
	Functor CreateFunctor(const std::vector<std::string>& lexems);
private:
	MapType m_commandMap;
};