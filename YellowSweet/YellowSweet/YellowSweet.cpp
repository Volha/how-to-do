// YellowSweet.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Tree.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Control::Tree<int> t; 
	t.Add(7);
	t.Add(10);
	t.Add(56);
	t.Add(4);
	t.Add(24);
	t.Add(5);
	auto v = t.Traverse();
	auto v2 = t.TraversSpecial();
	return 0;
}

