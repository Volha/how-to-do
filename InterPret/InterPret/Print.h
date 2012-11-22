#pragma once
#include "Operation.h"


class Print : public Operation
{
public:
	Print()
	{
		
	}

	Functor BuildFunctorFromParameters(const std::vector<std::string>& lexems)
	{
		if (lexems.size() != 2)
		{
			return Functor();
		}
		std::string word = lexems[1];
		return [=]()
		{
			std::cout << word << std::endl;
		};
	}
};


