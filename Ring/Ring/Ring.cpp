// Ring.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "RingClass.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	RingClass<int> r;
	r.AddNode(3);
	r.AddNode(10);
	r.AddNode(9);
	r.AddNode(15);
	r.AddNode(5);
	while (r.GetCurrentValue() != 3)
	{
		std::cout << r.GetCurrentValue() << "\n";
		r.MoveNext();
	}
	r.RemoveNode();
	int t = r.GetCurrentValue();
	r.MoveNext();
	t = r.GetCurrentValue();

	return 0;
}

