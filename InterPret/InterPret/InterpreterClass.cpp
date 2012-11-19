#include "stdafx.h"
#include "InterpreterClass.h"
#include <iostream>

InterpreterClass::InterpreterClass()
{
	InitializeMap();
}

void InterpreterClass::Print(const std::string& params)
{
	std::cout << params << "\n";
}

void InterpreterClass::Decorate(const std::string& params)
{
	std::cout << "*********" << params << "*********" << std::endl;
}

void InterpreterClass::Sum(const std::string& params)
{
	std::string firstParam, secondParam;
	if (params == "")
	{
		return;
	}
	firstParam = params.substr(0, params.find(" "));
	secondParam = params.substr(params.find(" ") + 1);
	if ((firstParam.size() != 0) && secondParam.size() != 0)
	{
		int first = std::stoi(firstParam);
		int second = std::stoi(secondParam);
		std::cout << first + second << std::endl ;
	}
	else
	{
		std::cout << "Wrong parameters" << std::endl;
	}
}

void InterpreterClass::InitializeMap()
{
	AddOperation("Print", Operation(ArgumentsList(STRING)));
	AddOperation("Add", Operation(ArgumentsList(INT, INT)));
	AddOperation("Sub", Operation(ArgumentsList(INT, INT)));
}

void InterpreterClass::AddOperation(const std::string& operationName, const Operation& operation)
{
	m_commandMap.insert(std::make_pair(operationName, operation));
}
// std::function
Functor InterpreterClass::CreateFunctor(const std::vector<std::string>& lexems)
{
	if (lexems.empty())
	{
		throw InvalidLineException();
	}
	const Operation& op = GetOperation(lexems[0]); // map.find
	return op.BuildFunctorFromParameters(lexems);
}

void InterpreterClass::RunCommand(const std::string& commandLine)
{
	std::string command, param;
	size_t position; 
	position = commandLine.find(" ");
	command = commandLine.substr(0, position);
	param = commandLine.substr(position + 1);

	try
	{
		Functor f = CreateFunctor(lexems);
		f();
	}
	catch(...)
	{
	
	}
	auto it = m_commandMap.find(command);
	if (it != m_commandMap.end())
	{
		auto p = it->second;
		(this->*p)(param);
	}
	else std::cout << "No command \n";
}

InterpreterClass::~InterpreterClass()
{
}

class InterpreterClass::Operation
{
public: 
	Operation();
	operator()()
	BuildFunctorFromParameters();
	
};