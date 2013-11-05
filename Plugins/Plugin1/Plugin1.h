#pragma once
#include "../Plugins/IPlugin.h"

class Plugin1 : public IPlugin
{
public:
	Plugin1();
	void DoCommand(const std::string & str);
	void PlaySample(unsigned short sample);
};