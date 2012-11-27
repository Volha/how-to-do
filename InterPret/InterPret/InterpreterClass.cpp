#include "stdafx.h"
#include "InterpreterClass.h"
#include <iostream>
#include <functional>
#include <algorithm>
#include <stdarg.h>
#include "Add.h"
#include "Print.h"
#include "Sub.h"
#include "RunThreads.h"
#include <boost\tokenizer.hpp>
#include <boost\lexical_cast.hpp>
#include <boost\thread.hpp>
#include "ThreadPool.h"

InterpreterClass::InterpreterClass()
{
	InitializeMap();
	m_strCommands.insert(std::make_pair("Add", ADD)); 
	m_strCommands.insert(std::make_pair("Sub", SUB)); 
	m_strCommands.insert(std::make_pair("Print", PRINT)); 
	m_strCommands.insert(std::make_pair("RunThreads", THREADS));
}

InterpreterClass::~InterpreterClass()
{

}

void InterpreterClass::InitializeMap()
{
	AddOperation(PRINT, ArgumentsList(1, STRING));
	AddOperation(ADD, ArgumentsList(2, INT, INT));
	AddOperation(SUB, ArgumentsList(2, INT, INT));
	AddOperation(THREADS, ArgumentsList(2, STRING, STRING));
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
	typedef  boost::char_separator<char> Separators;
	Separators sep("() ");
	std::vector<std::string> lexems;
	boost::tokenizer<Separators> tok(commandLine,sep);
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
		ThreadPool::Instance()->DoAsync(f);
	}

	catch(const InvalidLexemNumberException&)
	{
		std::cout << "Invalid number parameters" << std::endl;
	}
	
	catch(const std::bad_function_call&)
	{
		std::cout << "Bad functional call" << std::endl;
	}
	catch(const std::runtime_error& ia)
	{
		std::cout << ia.what() << std::endl;
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
	case THREADS:
		op = new RunThreads();
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
	
	std::unique_ptr<Operation> op(GetOperation(m_strCommands.find(lexems[0])->second));
	return op->BuildFunctorFromParameters(lexems);
}