#pragma once
#include <functional>
#include <vector>
#include <iostream>

class InvalidLexemNumberException
{};

class Operation
{
public: 
	typedef std::function<void()> Functor;
	enum CommandsEnum {ADD, SUB, PRINT};
	static Operation* GetOperation(CommandsEnum command);
	virtual Functor BuildFunctorFromParameters(const std::vector<std::string>& lexems) = 0;
	virtual ~Operation(){};
};