#pragma once
#include <stack>

class Article
{
public:	
	virtual ~Article(){};
	virtual void RunArticle(std::stack<int>& globalStack) = 0;
};