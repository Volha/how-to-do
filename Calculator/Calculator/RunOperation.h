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

	void RunArticle(std::stack<int>& globalStack, std::vector<std::string> tokens)
	{
		if (globalStack.empty())
		{
			throw std::runtime_error("Stack is empty");
		}
		auto it = std::find(tokens.begin(), tokens.end(), "run");
		++it;
		typedef boost::tokenizer<boost::char_separator<char>> TokenizeSep;
		boost::char_separator<char> sep("()");
		TokenizeSep tok(*it, sep);

		Interpreter interPr;
		interPr.PushStack(globalStack.top());
		globalStack.pop();
		auto s = Dictinary::Instance()->GetDictinary()->find(*tok.begin());
		if (s !=   Dictinary::Instance()->GetDictinary()->end())
		{
			for(size_t i = 0; i != s->second.size(); ++i)
			{
				try
				{
					auto f = interPr.GetFunctor(s->second[i]);
					ThreadPool::GetInstance()->DoAsync(f);
				}
				catch(const std::runtime_error& ia)
				{
					std::cout << ia.what() << std::endl;
				}
			}
		}
		else
		{
			std::cout << "Command haven't been found in dict" << std::endl;
		}


	}
private:
	std::stack<int> m_stack;
};