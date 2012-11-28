#pragma once
#include "Article.h"


class DotOperation : public Article
{
public:
	 DotOperation()
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