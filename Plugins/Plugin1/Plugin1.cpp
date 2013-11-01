#include "stdafx.h"
#include "Plugin1.h"
#include <iostream>

Plugin1::Plugin1()
{
	
}

void Plugin1::DoCommand(const std::string & str)
{
	std::cout << str << "\n";
}

void Plugin1::PlaySample(unsigned short sample)
{
	std::cout << "playing plugin1 " << sample << "\n";
}