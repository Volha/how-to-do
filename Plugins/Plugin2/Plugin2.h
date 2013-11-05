#pragma once
#include "../Plugins/IPlugin.h"

class Plugin2 : public IPlugin
{
public:
	Plugin2();
	void DoCommand(const std::string & str);
	void PlaySample(unsigned short sample);
};