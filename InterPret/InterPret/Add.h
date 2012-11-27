#pragma once
#include "Operation.h"
#include <stdexcept>
#include <boost\lexical_cast.hpp>

class Add : public Operation
{
public:
	Add()
	{

	}

	Functor BuildFunctorFromParameters(const std::vector<std::string>& lexems)
	{
		if (lexems.size() != 3)
		{
			return Functor();
		}
		
		try
		{
			int a =  boost::lexical_cast<int>(lexems[1]);
			int b =  boost::lexical_cast<int>(lexems[2]);
			return [=]()
			{
				std::cout << a + b << std::endl;
			};
		}
		catch(boost::bad_lexical_cast& ia)
		{
			std::cout << ia.what() << std::endl;
		}
		return Functor();
	}
};