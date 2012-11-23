// InterPret.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include "RunThreads.h"

int _tmain(int argc, _TCHAR* argv[])
{
	auto iC = std::make_shared<RunThreads>(); 
	iC->RunFile("file.txt");
	
	return 0;
}

