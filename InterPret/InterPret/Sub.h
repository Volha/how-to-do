#pragma once
#include "Operation.h"
#include <stdexcept>
#include <boost\lexical_cast.hpp>

class Sub : public Operation
{
public:
	Sub()
	{
		
	}
	
	Functor BuildFunctorFromParameters(const std::vector<std::string>& lexems)
	{
		if (lexems.size() != 3)
		{
			return Functor();// throw InvalidLexemNumberException();
		}
		
		try
		{
			int a = boost::lexical_cast<int>(lexems[1]);
			int b = boost::lexical_cast<int>(lexems[2]);
			return [=]()
			{
				std::cout << a - b << std::endl;
			};
		}
		catch(boost::bad_lexical_cast& ia)
		{
			//throw InvalidLexemFormatException();
			std::cout << ia.what() << std::endl;
		}
		return Functor();		
	}
};

