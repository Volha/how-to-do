#pragma once
#include "stdafx.h"
#include "Dictinary.h"
#include <stdarg.h>
#include <algorithm>
Dictinary* Dictinary::s_instance = nullptr;

Dictinary* Dictinary::Instance()
{
	if (s_instance == 0)
	{
		s_instance = new Dictinary();
	}
	return s_instance;
}

Dictinary::Dictinary()
{
	AddOperationToDict("+", Arguments(1, ADD));
	AddOperationToDict(".", Arguments(1, DOT));
	AddOperationToDict("mod", Arguments(1, MOD));
	AddOperationToDict("*", Arguments(1, MULT));
	AddOperationToDict("4to1", Arguments(1, FOURTHTO1));
	AddOperationToDict("3to1", Arguments(1, THIRDTO1));
	AddOperationToDict("dup", Arguments(1, DUP));
	AddOperationToDict(":", Arguments(1, COLON));
	AddOperationToDict("run", Arguments(1, RUNTHREAD));
}
std::vector<Dictinary::SimpleCommands> Dictinary::Arguments(size_t n,...)
{
	std::vector<SimpleCommands> paramsList;
	va_list p;
	SimpleCommands buf;
	va_start(p, n);

	while(n != 0)             
    { 
		buf = va_arg(p, SimpleCommands);
		paramsList.push_back(buf);
		--n;
	}
	va_end(p);

	return paramsList;
}

void Dictinary::AddOperationToDict(const std::string& name, std::vector<Dictinary::SimpleCommands>&& params)
{
	m_dictinary.insert(std::make_pair(name, params));
}

void Dictinary::AddNewOperation(const std::vector<std::string> tokens)
{
	std::vector<Dictinary::SimpleCommands> params;
	DictinaryType::iterator s;
	auto colonItBegin = std::find(tokens.begin(), tokens.end(), ":");
	auto colonItEnd = std::find(tokens.begin(), tokens.end(), ";");

	if (m_dictinary.find( *(++colonItBegin)) != m_dictinary.end())
	{
		throw std::runtime_error("The command with this name exists");
	}
	
	if (colonItEnd == tokens.end())
	{
		throw std::runtime_error("The opration should contain ; ");
	}
	for(auto it = ++colonItBegin; it != colonItEnd; ++it)
	{
		s = m_dictinary.find(*it);
		if (s !=  m_dictinary.end())
		{
			for(size_t j = 0; j < s->second.size(); ++j)
			params.push_back(s->second[j]);
		}
	}
	AddOperationToDict(*(--colonItBegin), std::move(params));
}

const Dictinary::DictinaryType* Dictinary::GetDictinary() const
{
	return &m_dictinary;
}