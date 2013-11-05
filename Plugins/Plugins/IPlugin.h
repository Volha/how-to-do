#pragma once
#include <string>

class IPlugin
{
public:
	virtual ~IPlugin(){}
	virtual void DoCommand(const std::string & str) = 0;
	virtual void PlaySample(unsigned short sample) = 0;
};