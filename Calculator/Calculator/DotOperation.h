#pragma once
#include "Article.h"
#include <iostream>

class DotOperation : public Article
{
public:
	DotOperation()
	{
		
	};
	
	void RunArticle(std::shared_ptr<std::stack<int>> globalStack, std::vector<std::string> tokens) 
	{
		if (globalStack->empty())
		{
			throw std::runtime_error("The stack is empty");
		}
		std::cout << globalStack->top() << std::endl;
		globalStack->pop();
	}
};