#include "stdafx.h"
#include "InterpreterClass.h"
#include <iostream>
#include <functional>
#include <algorithm>
#include <stdarg.h>
#include "Add.h"
#include "Print.h"
#include "Sub.h"
#include <boost\tokenizer.hpp>
#include <boost\lexical_cast.hpp>

InterpreterClass::InterpreterClass()
{
	InitializeMap();
	m_strCommands.insert(std::make_pair("Add", ADD)); 
	m_strCommands.insert(std::make_pair("Sub", SUB)); 
	m_strCommands.insert(std::make_pair("Print", PRINT)); 
}

InterpreterClass::~InterpreterClass()
{
}

void InterpreterClass::InitializeMap()
{
	AddOperation(PRINT, ArgumentsList(1, STRING));
	AddOperation(ADD, ArgumentsList(2, INT, INT));
	AddOperation(SUB, ArgumentsList(2, INT, INT));
}

std::vector<InterpreterClass::TypesEnum> InterpreterClass::ArgumentsList(size_t n, ...)
{
	std::vector<InterpreterClass::TypesEnum> paramsList;
	va_list p;
	InterpreterClass::TypesEnum buf;
	va_start(p, n);

	while(n != 0)             
    { 
		buf = va_arg(p, InterpreterClass::TypesEnum);
		paramsList.push_back(buf);
		--n;
	}

	va_end(p);
	return paramsList;
}

void InterpreterClass::AddOperation(CommandsEnum command, std::vector<InterpreterClass::TypesEnum> param)
{
	m_commandMap.insert(std::make_pair(command, param));
}

std::vector<std::string> InterpreterClass::GetLexemsFromString(const std::string& commandLine)
{
	std::vector<std::string> lexems;
	boost::tokenizer<> tok(commandLine);
	std::copy(tok.begin(), tok.end(), std::back_inserter(lexems));
	return lexems;
}

void InterpreterClass::RunCommand(const std::string& commandLine)
{
	std::vector<std::string> lexems;
	lexems = GetLexemsFromString(commandLine);
	try
	{
		Functor f = CreateFunctor(lexems);
		f();
	}
	catch(const InvalidLexemNumberException&)
	{
		
	}
	catch(const std::bad_function_call&)
	{
		std::cout << "Bad functional call" << std::endl;
	}
}


Operation* InterpreterClass::GetOperation(CommandsEnum command)
{
	Operation* op;
	switch(command)
	{
	case ADD: 
		op = new Add();
		break;
	case SUB:
		op = new Sub();
		break;
	case PRINT:
		op = new Print();
		break;
	}
		return op;
}

// std::function
InterpreterClass::Functor InterpreterClass::CreateFunctor(const std::vector<std::string>& lexems)
{
	if (lexems.empty() || m_strCommands.find(lexems[0]) == m_strCommands.end())
	{
		throw std::runtime_error("Invalid command or parameters");
	}
	
	Operation* op = GetOperation(m_strCommands.find(lexems[0])->second); // map.find
	return op->BuildFunctorFromParameters(lexems);
}