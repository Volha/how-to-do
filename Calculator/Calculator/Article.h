#pragma once
#include <stack>
#include "Interpreter.h"

class Article
{
public:	
	virtual ~Article(){};
	virtual void RunArticle(std::stack<int>& globalStack, std::vector<std::string> tokens) = 0;
};