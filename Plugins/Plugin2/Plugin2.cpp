#include "stdafx.h"
#include "Plugin2.h"
#include <iostream>

Plugin2::Plugin2()
{
	
}

void Plugin2::DoCommand(const std::string & str)
{
	std::cout << str << " decorated\n"; 
}

void Plugin2::PlaySample(unsigned short sample)
{
	std::cout << "playing plugin 2 " << sample << "\n";
}