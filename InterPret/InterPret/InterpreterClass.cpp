#include "stdafx.h"
#include "InterpreterClass.h"
#include <iostream>

InterpreterClass::InterpreterClass()
{
	m_commandMap = InitializeMap();
}

void InterpreterClass::Print(const std::string& params)
{
	std::cout << params << "\n";
}

void InterpreterClass::Decorate(const std::string& params)
{
	std::cout << "*********" << params << "*********" << std::endl;
}

MapType* InterpreterClass::InitializeMap()
{
	MapType* commandMap = new MapType;
	commandMap->insert(std::pair<std::string, Function>("Print", &InterpreterClass::Print)); 
	commandMap->insert(std::pair<std::string, Function>("Decorate", &InterpreterClass::Decorate));
	return commandMap;
}

void InterpreterClass::RunCommand(const std::string& commandLine)
{
	std::string command, param;
	size_t position; 
	position = commandLine.find(" ");
	command = commandLine.substr(0, position);
	param = commandLine.substr(position + 1);

	MapType* commandMap(InitializeMap());

	MapType::iterator it = commandMap->find(command);
	if (it != commandMap->end())
	{
		auto p = it->second;
		(this->*p)(param);
	}
	else std::cout << "No command \n";
}

InterpreterClass::~InterpreterClass()
{
	delete m_commandMap;
}