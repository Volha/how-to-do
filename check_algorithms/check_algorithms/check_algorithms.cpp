// check_algorithms.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVector(vector<int>& vectorForFunc)
{
	for (int i = 0; i < vectorForFunc.size(); i++)
	{
	cout << vectorForFunc[i] << "  ";
	}
	cout << "\n";
};

bool IsEqual(const vector<int>& sortVec, const vector<int>& vecShould)
{
	return equal(sortVec.begin(), sortVec.end(), vecShould.begin());
}

void CheckResults(bool res)
{
	if (res)
	{
		 cout << "Right\n";
	}
	else 
	{	
		cout << "Wrong\n";
	}
}

void TestSort()
{
	vector<int> vectorForTest;
	vector<int> vectorShouldBe;
	vectorForTest.push_back(90);
	vectorForTest.push_back(2);
	vectorForTest.push_back(15);
	vectorShouldBe.push_back(2);
	vectorShouldBe.push_back(15);
	vectorShouldBe.push_back(90);

	PrintVector(vectorForTest);
	PrintVector(vectorShouldBe);
	
	sort(vectorForTest.begin(), vectorForTest.end());
	CheckResults(IsEqual(vectorForTest, vectorShouldBe));
	
	PrintVector(vectorForTest);
}

int _tmain(int argc, _TCHAR* argv[])
{
	TestSort();
	cin.get();
	return 0;
}



