#pragma once
#include <string>

class SomeClass
{
public:
	SomeClass(int size, const std::string& str);
	SomeClass(const SomeClass& s);
	SomeClass(SomeClass&& s);
	SomeClass& operator = (const SomeClass& s);
	~SomeClass();
	const std::string& GetString() const;
	const int* GetPointer() const;
	const int* GetArray() const;
	int GetArraySize() const;


private:
	std::string m_string;
	int* m_intPointer;
	int* m_array;
	int m_arraySize;
};