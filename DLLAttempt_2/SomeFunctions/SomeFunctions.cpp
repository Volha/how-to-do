// SomeFunctions.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "SomeFunctions.h"
#include <iostream>

void PrintNumbers()
{
	for (int i = 0; i < 20; ++i)
	{
		std::cout << i << " ";
		std::cout << std::endl;
	}
}

void PrintLetters()
{
	
		std::cout << "I am from FunctionsToPrint";
		std::cout << std::endl;
	
}

