#pragma once
#include <string>


class IPlugin
{
public:
	virtual ~IPlugin(){};
	virtual void Init() = 0;
	virtual void Release() = 0;
	
	virtual void DoOperation(int a, int b) = 0;
	virtual const std::string& GetNameOperation() const = 0;
};


