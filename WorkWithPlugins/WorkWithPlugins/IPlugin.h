#pragma once
#include <string>


class IPlugin
{
public:
	virtual void DoOperation(int a, int b) = 0;
	virtual const std::string& GetNameOperation() const = 0;
};


