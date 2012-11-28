#pragma once
#include <stack>
#include <string>
#include <stack>
#include <map>
#include <boost\tokenizer.hpp>
#include <boost\lexical_cast.hpp>
#include "Article.h"

class Interpreter
{
public:
	enum SimpleCommands {ADD, DOT, MOD};
	typedef std::function<void()> Functor;
	typedef std::map<std::string, std::vector<SimpleCommands>> DictinaryType;
	Interpreter();
	void RunInterpret(const std::string& commandLine);

private:	
	std::vector<std::string>* Tokenizer(const std::string& str);	
	bool IsTokenNumber(const std::string& str);
	Functor GetArticleFromParams(SimpleCommands command);

private:
	std::stack<int> m_stack;
	std::vector<std::string> m_tokens;
	DictinaryType m_dictinary;
};