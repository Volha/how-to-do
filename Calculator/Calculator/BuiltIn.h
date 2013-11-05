#pragma once
#include "Article.h"
#include <stack>
class BuiltIn : public Article
{
public:
	BuiltIn();
	virtual ~BuiltIn();
	virtual void operator()(std::stack<int>* globalStack) = 0;
};