#include "stdafx.h"
#include <algorithm>
#include <stdarg.h>
#include <boost\thread.hpp>
#include "Interpreter.h"
#include "AddOperation.h"
#include "DotOperation.h"
#include "ModOperation.h"
#include "FourthToFirst.h"
#include "ThirdToFirst.h"
#include "MultOperation.h"
#include "DupOperation.h"
#include "ColonOperation.h"
#include "RunOperation.h"

Interpreter::Interpreter()
{
	
}


void Interpreter::RunInterpret(const std::string& commandLine)
{
	m_tokens = Tokenizer(commandLine);
	for(std::vector<std::string>::iterator it = m_tokens.begin(); it != m_tokens.end(); ++it)
	{
		if (IsTokenNumber(*it))
		{
			m_stack.push(boost::lexical_cast<int>(*it));
		}
		else
		{
			FindAndRun(*it);
			return;
		}
	}
}

void Interpreter::FindAndRun(const std::string& str)
{
	auto s = Dictinary::Instance()->GetDictinary()->find(str);
	if (s !=   Dictinary::Instance()->GetDictinary()->end())
	{
		for(size_t i = 0; i != s->second.size(); ++i)
		{
			try
			{
				auto f = GetFunctor(s->second[i]);
				f();
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

std::vector<std::string> Interpreter::Tokenizer(const std::string& str)
{
	typedef boost::tokenizer<boost::char_separator<char>> TokenizeSep;
	boost::char_separator<char> sep(" ");
	TokenizeSep tok(str, sep);
	std::vector<std::string> temp_str;
	std::copy(tok.begin(), tok.end(), std::back_inserter(temp_str));
	return temp_str;
}

bool Interpreter::IsTokenNumber(const std::string& str) const
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

Article* Interpreter::GetArticle(Dictinary::SimpleCommands command)
{
	switch(command)
	{
	case Dictinary::ADD:
		return new AddOperation();
	case Dictinary::MOD:
		return new ModOperation();
	case Dictinary::DOT:
		return new DotOperation();
	case Dictinary::FOURTHTO1:
		return new FourthToFirst();
	case Dictinary::THIRDTO1:
		return new ThirdToFirst();
	case Dictinary::MULT:
		return new MultOperation();		
	case Dictinary::DUP:
		return new DupOperation();
	case Dictinary::COLON:
		return new ColonOperation();
	case Dictinary::RUNTHREAD:
		return new RunOperation();
	}
	return nullptr;
}

Interpreter::Functor Interpreter::GetFunctor(Dictinary::SimpleCommands command)
{
	auto art = GetArticle(command);
	
	return [=]()
	{
		art->RunArticle(m_stack, m_tokens);
	};
}

std::stack<int>* Interpreter::GetStack()
{
	return &m_stack;
}

std::vector<std::string>* const Interpreter::GetTokens()
{
	return &m_tokens;
}
void Interpreter::PushStack(int i)
{
	m_stack.push(i);
}
