// check_algorithms.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Print(int i)
{
	cout << i << "  ";
}

struct P
{
	size_t m_c;
	P(size_t c) : m_c(c)
	{
	
	}
	void operator()(int i)
	{
		cout << i + m_c << "  ";
	}
};

void PrintVector(vector<int>& vectorForFunc)
{	
	for_each
	(
		vectorForFunc.begin(),
		vectorForFunc.end(),
		[](int i)
		{
			cout << i << "  ";
			
		}
	);
	//for (auto ib = vectorForFunc.begin(), ie = vectorForFunc.end(); ib != ie; ++ib)
	//{
	//	cout << *ib << "  ";
	//}
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
		 cout << "right\n";
	}
	else 
	{	
		cout << "wrong\n";
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

	sort(vectorForTest.begin(), vectorForTest.end());
	CheckResults(IsEqual(vectorForTest, vectorShouldBe));
	
	vectorForTest.erase(vectorForTest.begin(), vectorForTest.end());
	vectorForTest.push_back(3);
	vectorShouldBe.erase(vectorShouldBe.begin(),vectorShouldBe.end());
	vectorShouldBe.push_back(3);

	sort(vectorForTest.begin(),vectorForTest.end());
	CheckResults(IsEqual(vectorForTest, vectorShouldBe));
	
}

void TestFind()
{
	vector<int> vecForTest;
	vecForTest.push_back(0);
	vecForTest.push_back(5);
	vecForTest.push_back(100);
	vecForTest.push_back(555);
	cout << "Not found: ";
	CheckResults((vecForTest.end() == find(vecForTest.begin(), vecForTest.end(), 56)));
	cout << "The first found value: ";
	CheckResults((vecForTest.begin()+1 == find(vecForTest.begin(), vecForTest.end(), 5)));
	vecForTest[0] = 555;
	vecForTest[1] = 555;
	vecForTest[2] = 555;
	vecForTest[3] = 555;
	cout << "The first found value in set of similar elements: ";
	CheckResults((vecForTest.begin() == find(vecForTest.begin(), vecForTest.end(), 555)));
	vecForTest.erase(vecForTest.begin(), vecForTest.end());
}

void TestBinarySearch()
{
	vector<int> vecForTest;
	vecForTest.push_back(0);
	vecForTest.push_back(5);
	vecForTest.push_back(100);
	vecForTest.push_back(555);
	cout << "Simple search: ";
	CheckResults(binary_search(vecForTest.begin(), vecForTest.end(), 0));
	cout << "The element, which is not in the set: ";
	CheckResults(!binary_search(vecForTest.begin(), vecForTest.end(), 10));
	vecForTest.erase(vecForTest.begin()+1, vecForTest.end());
	cout << "One element: ";
	CheckResults(binary_search(vecForTest.begin(), vecForTest.end(), 0));
	cout << "No elements: ";
	CheckResults(!binary_search(vecForTest.begin(), vecForTest.end(), 0));

}

class CheckFE {
  public:
   CheckFE() : num(0), sum(0) {}
   size_t num;    
   int sum; 
   void operator() (int elem) {
        num++;          
        sum += elem;    
    }
};

void TestForEach()
{
	vector<int> vecForTest;
	vecForTest.push_back(0);
	vecForTest.push_back(5);
	vecForTest.push_back(10);
	vecForTest.push_back(7);
	CheckFE chFE = for_each(
		vecForTest.begin(), 
		vecForTest.end(), 
		CheckFE());
	cout << " Simple checking for_each: ";
	CheckResults((chFE.num == vecForTest.size())&&(chFE.sum == 22));
	cout << " No elements: ";
	vecForTest.erase(vecForTest.begin(), vecForTest.end());
	chFE = for_each(
		vecForTest.begin(), 
		vecForTest.end(), 
		CheckFE());
	CheckResults((chFE.num == vecForTest.size())&&(chFE.sum == 0));
};


int _tmain(int argc, _TCHAR* argv[])
{
	argc;argv;
	cout << "SORT\n";
	TestSort();
	cout << "FIND\n";
	TestFind();
	cout << "BINARY_SEARCH\n";
	TestBinarySearch();
	cout << "FOR_EACH\n";
	TestForEach();
	cout << "ACCUMULATE\n";

	cin.get();
	return 0;
}



