#pragma once
#include "Operation.h"
#include <fstream>
#include "InterpreterClass.h"
#include "ThreadPool.h"

class RunThreads : public Operation
{
public:
	RunThreads()	
	{
		ThreadPool::Instance()->AddRef(); 
	}
	
	~RunThreads()	
	{
		ThreadPool::Instance()->DecRefs(); 
	}

	Functor BuildFunctorFromParameters(const std::vector<std::string>& lexems)
	{
		if (lexems.size() != 2)
		{
			throw InvalidLexemNumberException();
		}
		std::string fileName = lexems[1];
		return [=](){RunFile(fileName);};
	}

	void RunFile(const std::string& fileName)
	{
		auto iC = std::make_shared<InterpreterClass>(); 
		std::fstream f;
		std::string commandLine;
		
		f.open(fileName);
		if (f.is_open())
		{
			while(f.good())
			{
				getline(f, commandLine);
				iC->RunCommand(commandLine);
			}
		}
 		f.close();
	}
};
