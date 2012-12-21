#pragma once
#include <string>
#include "../WorkWithPlugins/IPlugin.h"


extern "C" __declspec(dllexport) HRESULT GetPlugin(IPlugin** pPlugin);
//extern "C" __declspec(dllexport) HRESULT FreePlugin(IPlugin** pPlugin);

class PluginAdd : public IPlugin
{
public:
	PluginAdd();
	~PluginAdd();

	void Init();
	void Release();
	void DoOperation(int a, int b);
	const std::string& GetNameOperation() const;
private:
	std::string m_name;
	int m_ref;
};