// InterPret.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <map>
#include <iostream>
#include <string>
#include <fstream>

typedef void (*Function)(const std::string& param);
typedef std::map<std::string, Function> MapType;

void Print(const std::string& params)
{
	std::cout << params << "\n";
}

void Decorate(const std::string& params)
{
	std::cout << "*********" << params << "*********" << std::endl;
}

MapType* InitializeMap()
{
	MapType* commandMap = new MapType;
	commandMap->insert(std::pair<std::string, Function>("Print", Print)); 
	commandMap->insert(std::pair<std::string, Function>("Decorate", Decorate));
	return commandMap;
}

void RunCommand(const std::string& commandLine)
{
	std::string command, param;
	size_t position; 
	position = commandLine.find(" ");
	command = commandLine.substr(0, position);
	param = commandLine.substr(position + 1);
	MapType* commandMap(InitializeMap());

	MapType::iterator it = commandMap->find(command);
	if (it != commandMap->end())
	{
		it->second(param);
	}
	else std::cout << "No command \n";
}




int _tmain(int argc, _TCHAR* argv[])
{
	std::string commandLine;
	std::fstream f;
	//MapType* commandMap(InitializeMap());
	
	f.open("file.txt");
	if (f.is_open())
	{
		while(f.good())
		{
			getline(f, commandLine);
			RunCommand(commandLine);
		}
	}
 	f.close();
	return 0;
}

