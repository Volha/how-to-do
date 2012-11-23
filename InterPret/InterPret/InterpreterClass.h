#pragma once
#include <string>
#include <map>
#include <vector>
#include "Operation.h"

class InterpreterClass
{
	typedef std::function<void()> Functor; 
	enum TypesEnum {STRING, INT};
	enum CommandsEnum {ADD, SUB, PRINT, THREADS};
	typedef std::map<CommandsEnum, std::vector<TypesEnum>> MapType;
	typedef std::map<std::string, CommandsEnum> CommandMap;

public:
	InterpreterClass();
	~InterpreterClass();
	void RunCommand(const std::string& commandLine);
	
private:
	void InitializeMap();
	Operation* InterpreterClass::GetOperation(const CommandsEnum command);
	std::vector<InterpreterClass::TypesEnum> InterpreterClass::ArgumentsList(size_t n, ...);
	void AddOperation(CommandsEnum command, std::vector<InterpreterClass::TypesEnum> param);
	Operation::Functor CreateFunctor(const std::vector<std::string>& lexems);
	std::vector<std::string> GetLexemsFromString(const std::string& commandLine);

private:
	CommandMap m_strCommands; 
	MapType m_commandMap;
};