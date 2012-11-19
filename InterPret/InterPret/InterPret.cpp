// InterPret.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include "InterpreterClass.h"

int _tmain(int argc, _TCHAR* argv[])
{
	std::string commandLine;
	std::fstream f;
	typedef std::shared_ptr<InterpreterClass> ICptr;
	auto iC = std::make_shared<InterpreterClass>(); 
	
	f.open("file.txt");
	if (f.is_open())
	{
		while(f.good())
		{
			getline(f, commandLine);
			iC->RunCommand(commandLine);
		}
	}
 	f.close();
	return 0;
}

