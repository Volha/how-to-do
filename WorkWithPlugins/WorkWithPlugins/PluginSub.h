#pragma once
#include "IPlugins.h"

class PluginSub : public IPlugins
{
public:
	void DoOperation(int a, int b)
	{
		//from DLL
	}
	std::string GetNameOperation()
	{
		return m_nameOperation;
	}
private:
	std::string m_nameOperation;
};