// check_algorithms.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "conio.h"
#include <vector>
#include <algorithm>
using namespace std;

void printVector(vector<int> vectorForFunc)
{
	for (int i=0; i<vectorForFunc.size(); i++)
	{
	cout<<vectorForFunc[i]<<"  ";
	}
	cout<<"\n";
};

bool isEqual(vector<int> VB, vector<int> VA)
{
	bool equality=true;
	if (VB.size()==VA.size())
	{
	for(int i=1; i<VB.size(); i++)
		if (VB[i]!=VA[i])
		{
		equality=false;
		}
	}
	else equality=false;
	return equality;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> vectorForTest;
	vector<int> vectorShouldBe;
	vectorForTest.push_back(90);
	vectorForTest.push_back(2);
	vectorForTest.push_back(15);
	vectorShouldBe.push_back(2);
	vectorShouldBe.push_back(15);
	vectorShouldBe.push_back(90);

	printVector(vectorForTest);
	printVector(vectorShouldBe);
	
	sort(vectorForTest.begin(), vectorForTest.end());

	if (isEqual(vectorForTest, vectorShouldBe))
		cout<<"Right\n";
	else cout<<"Wrong\n";

	printVector(vectorForTest);
	getch();
	return 0;
}



