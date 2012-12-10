#pragma once
#include <stack>
#include "Interpreter.h"
#include <memory>
class Article
{
public:	
	virtual ~Article(){};
	virtual void RunArticle(std::shared_ptr<std::stack<int>> globalStack, std::vector<std::string> tokens) = 0;
};