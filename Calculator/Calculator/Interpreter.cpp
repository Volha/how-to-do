#include "stdafx.h"
#include <algorithm>
#include "Interpreter.h"
#include "AddOperation.h"
#include "DotOperation.h"
#include "ModOperation.h"

Interpreter::Interpreter()
{
	
}

void Interpreter::RunInterpret(const std::string& commandLine)
{
	m_tokens = *Tokenizer(commandLine);
	for(std::vector<std::string>::iterator it = m_tokens.begin(); it != m_tokens.end(); ++it)
	{
		if (IsTokenNumber(*it))
		{
			m_stack.push(boost::lexical_cast<int>(*it));
		}
		else
		{
			if (m_tokens[0] == ":")
			{
				//add new operation
			}
			else
			{
				auto s = std::find(m_dictinary.begin(), m_dictinary.end(), *it);
				if (s !=  m_dictinary.end())
				{
					GetArticleFromParams(s->second);
				}
				//find in dictinary and run
			}
		}
	}
}


std::vector<std::string>* Interpreter::Tokenizer(const std::string& str)
{
	typedef boost::tokenizer<boost::char_separator<char>> TokenizeSep;
	boost::char_separator<char> sep(" ");
	TokenizeSep tok(str, sep);
	std::vector<std::string>* temp_str;
	for(TokenizeSep::iterator it = tok.begin(); it != tok.end(); ++it)
	{
		temp_str->push_back(*it);
	}
	return temp_str;
}

bool Interpreter::IsTokenNumber(const std::string& str)
{
	try 
	{
		boost::lexical_cast<int>(str);
		return true;
	}
	catch (boost::bad_lexical_cast&)
	{
		return false;	
	}
}

//void Interpreter::AddNewOperation(const std::string& commandLine)

Interpreter::Functor Interpreter::GetArticleFromParams(SimpleCommands command)
{
	Article* art;
	switch(command)
	{
	case ADD:
		art = new AddOperation();
		break;
	case MOD:
		art = new ModOperation();
		break;
	case DOT:
		art = new DotOperation();
		break;
	}
	
	return [=]()
	{
		art->RunArticle(m_stack);
	};
}

