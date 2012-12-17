#pragma once
#include "IPlugins.h"

class PluginAdd : public IPlugins
{
public:
	void DoOperation(int a, int b)
	{
		
	}
	std::string GetNameOperation()
	{
		return m_nameOperation;
	}
private:
	std::string m_nameOperation;
};