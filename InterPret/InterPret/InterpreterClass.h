#pragma once
#include <string>
#include <map>
class InterpreterClass;

typedef void (InterpreterClass:: *Function)(const std::string& param);
typedef std::map<std::string, Function> MapType;

class InterpreterClass
{
public:
	InterpreterClass();
	~InterpreterClass();
	MapType* InitializeMap();
	void RunCommand(const std::string& commandLine);

private:
	void Print(const std::string& params = "");
	void Decorate(const std::string& params = "");

private:
	MapType* m_commandMap;
};