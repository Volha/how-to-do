#pragma once
#include "Article.h"
#include <vector>

class FourthToFirst : public Article
{
public:
	FourthToFirst()
	{
		
	};
	
	void RunArticle(std::stack<int>& globalStack, std::vector<std::string> tokens) 
	{
		if (globalStack.size() < 4)
		{
			throw std::runtime_error("Invalid numbers in stack");
		}
		std::vector<int> y;
		for (size_t i = 0; i < 4; ++i)
		{
			y.push_back(globalStack.top());
			globalStack.pop();
		}
		
		for (size_t i = 0; i < 4; ++i)
		{		
			globalStack.push(y[i]);
		}
	}
	
};