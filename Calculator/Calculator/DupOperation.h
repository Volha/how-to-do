#pragma once
#include "Article.h"


class DupOperation : public Article
{
public:
	DupOperation()
	{
		
	};
	
	void RunArticle(std::stack<int>& globalStack, std::vector<std::string> tokens) 
	{
		if (globalStack.empty())
		{
			throw std::runtime_error("Stack is empty");
		}
		
		int a = globalStack.top();
		globalStack.push(a);
	}
};