#pragma once
#include "Article.h"
#include "D:\!study_dev\how-to-do\Coordinator\ThreadPool\ThreadPool.h"
#include <boost\tokenizer.hpp>
#include "Interpreter.h"
class RunOperation : public Article
{
public:
	RunOperation()
	{
		
	};

	void RunArticle(std::shared_ptr<std::stack<int>> globalStack, std::vector<std::string> tokens)
	{
		if (globalStack->size() < 2)
		{
			throw std::runtime_error("Invalid number of parameters");
		}
		auto it = std::find(tokens.begin(), tokens.end(), "run");
		++it;
		typedef boost::tokenizer<boost::char_separator<char>> TokenizeSep;
		boost::char_separator<char> sep("()", ",");
		TokenizeSep tok(*it, sep);

		int firstForStack  = globalStack->top();
		globalStack->pop();
		int secondForStack = globalStack->top();
		globalStack->pop();
		std::string commandLine = *tok.begin();
		
		auto s = Dictinary::Instance()->GetDictinary()->find(*tok.begin());
		if (s ==   Dictinary::Instance()->GetDictinary()->end())
		{
			std::cout << "Command haven't been found in dict" << std::endl;
		}
		else
		{ 
				try
				{
					auto f = [=]()
					{
						Interpreter iP;
						iP.PushStack(secondForStack);
						iP.PushStack(firstForStack);
						iP.RunInterpret(commandLine);
					};
					ThreadPool::GetInstance()->DoAsync(f);
				}
				catch(const std::runtime_error& ia)
				{
					std::cout << ia.what() << std::endl;
				}
			}
	}
};