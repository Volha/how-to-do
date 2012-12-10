#pragma once
#include "Article.h"
#include <vector>

class ColonOperation : public Article
{
public:
	ColonOperation()
	{
		
	};
	
	void RunArticle(std::shared_ptr<std::stack<int>> globalStack, std::vector<std::string> tokens) 
	{
		try
			{
				Dictinary::Instance()->AddNewOperation(tokens);
			}
			catch(const std::runtime_error& ia)
			{
				std::cout << ia.what() << std::endl;
			}
	}
};