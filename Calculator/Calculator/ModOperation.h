#pragma once
#include "Article.h"


class ModOperation : public Article
{
public:
	ModOperation()
	{
		
	};
	
	void RunArticle(std::stack<int>& globalStack, std::vector<std::string> tokens) 
	{
		if (globalStack.size() < 2)
		{
			throw std::runtime_error("Invalid number of parameters");
		}
		int a = globalStack.top();
		globalStack.pop();
		int b = globalStack.top();
		globalStack.pop();
		globalStack.push(a % b);
		
	}
};