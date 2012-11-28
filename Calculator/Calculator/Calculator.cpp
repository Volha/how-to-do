// Calculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Interpreter.h"

int _tmain(int argc, _TCHAR* argv[])
{
	std::string commandLine;
	
	Interpreter iC;
	do
	{
		std::getline(std::cin, commandLine);
		iC.RunInterpret(commandLine);
	}
	while (commandLine!= "exit");

	return 0;
}

