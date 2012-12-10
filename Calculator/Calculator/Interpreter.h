#pragma once
#include <stack>
#include <string>
#include <stack>
#include <map>
#include <boost\tokenizer.hpp>
#include <boost\lexical_cast.hpp>
#include "Article.h"
#include "Dictinary.h"

class Interpreter
{
public:
	typedef std::function<void()> Functor;
	Interpreter();
	~Interpreter();
	void RunInterpret(const std::string& commandLine);
	
	void PushStack(int i);
	std::vector<std::string>* const GetTokens();
	Functor GetFunctor(Dictinary::SimpleCommands command);
private:	
	std::vector<std::string> Tokenizer(const std::string& str);	
	bool IsTokenNumber(const std::string& str) const;
	
	void FindAndRun(const std::string& str);
	Article* GetArticle(Dictinary::SimpleCommands command);
	void RunThread(const std::string& str);
private:
	std::shared_ptr<std::stack<int>> m_stack;
	std::vector<std::string> m_tokens;
	
};