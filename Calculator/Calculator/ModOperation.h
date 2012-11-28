#pragma once
#include "Article.h"


class ModOperation : public Article
{
public:
	ModOperation()
	{
		
	};
	
	void RunArticle(std::stack<int>& globalStack) 
	{
		if (globalStack.size() > 2)
		{
			int a = globalStack.top();
			globalStack.pop();
			int b = globalStack.top();
			globalStack.pop();
			globalStack.push(a + b);
		}
	}
};