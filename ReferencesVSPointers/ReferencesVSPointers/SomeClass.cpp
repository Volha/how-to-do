#include "stdafx.h"
#include "SomeClass.h"
#include <iostream>

SomeClass::SomeClass(int size, const std::string& str)
	: m_string(str)
	, m_intPointer(new int)
	, m_arraySize(size)
	, m_array(new int[size])
{
	std::fill(m_array, m_array + m_arraySize, 0);
}

SomeClass::SomeClass(const SomeClass& s)
	: m_string(s.m_string)
	, m_intPointer(new int(*s.m_intPointer))
	, m_array(new int[s.m_arraySize])
	, m_arraySize(s.m_arraySize)
{
	std::copy(s.m_array, s.m_array + s.m_arraySize, m_array);
}

SomeClass::SomeClass(SomeClass&& s)
	: m_string(std::move(s.m_string))
	, m_intPointer(s.m_intPointer)
	, m_array(s.m_array)
	, m_arraySize(s.m_arraySize)
{
	s.m_arraySize = 0;
	s.m_intPointer = nullptr;
	s.m_array = nullptr;
}

SomeClass& SomeClass::operator = (const SomeClass& s)
{
	if (this != &s)
	{
		this->m_string = s.m_string;
		this->m_intPointer = new int(*s.m_intPointer);
		this->m_array = new int[s.m_arraySize];
		this->m_arraySize = s.m_arraySize;
		std::copy(s.m_array, s.m_array + s.m_arraySize, m_array);
	}
	return *this;
 }

SomeClass::~SomeClass()
{
	delete [] m_array;
	delete m_intPointer;
}

const std::string& SomeClass::GetString() const
{
	return m_string;
}

const int* SomeClass::GetPointer() const
{
	return m_intPointer;
}

const int* SomeClass::GetArray() const
{
	return m_array;
}

int SomeClass::GetArraySize() const
{
	return m_arraySize;
}