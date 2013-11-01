// ReferencesVSPointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SomeClass.h"
#include <iostream>

void PrintRef(const SomeClass& s)
{
	std::cout << s.GetString() << "\n";
	std::cout << s.GetPointer() << "\n";
	for(int i = 0; i < s.GetArraySize(); ++i)
	{
		std::cout << s.GetArray()[i];
	}
}

void PrintPointer(const SomeClass* s)
{
	PrintRef(*s);
}

SomeClass CreateObject(int arraySize, const std::string& str)
{
	SomeClass s(arraySize, str); 
	return s; //move constructor
}

SomeClass* CreateObjectPoint(int arraySize, const std::string& str)
{
	SomeClass* s = new SomeClass(arraySize, str);
	return s;
}

void CreateParams(int arraySize, const std::string& str, SomeClass& m)
{
	m = CreateObject(arraySize, str);
}

void CreatePointer(int arraySize, const std::string& str, SomeClass* n)
{
	*n = *CreateObjectPoint(arraySize, str);
}

int _tmain(int argc, _TCHAR* argv[])
{
	/*{
		SomeClass m(2, "str1");
		std::cout << m.GetString();
		SomeClass n1(m);
		SomeClass* n = new SomeClass(4, "str2");
		std::cout << n1.GetString();
		m.GetArray()[0] = 9;
		m.GetArray()[1] = 0;
	
		PrintRef(m);
		PrintPointer(n);
		SomeClass mm(CreateObject(10, "Create"));
		PrintRef(mm);
		SomeClass* point = CreateObjectPoint(3, "Pointer");
	
		CreateParams(4, "re create", m);
		CreatePointer(20, "reLax", n);
	}*/

	{
		SomeClass big(4050, "big"); 
		SomeClass n(10, "ty");
		n = big;
		void (*f)(const SomeClass& s);
		
		f = &PrintRef;
		f(big);
		void (*g)(const SomeClass* s);
		g = &PrintPointer;
		
		g(CreateObjectPoint(54, "PointerObject"));

	}
	return 0;
}

