// check_algorithms.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

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
	if (sortVec.size() == vecShould.size())
	{
	return equal(sortVec.begin(), sortVec.end(), vecShould.begin());
	}
	else return false;
}

void CheckResults(bool res)
{
	if (res)
	{
		 cout << "right\n";
	}
	else 
	{	
		cout << "!!!!ACHTUNG!!!!\n";
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
	
	cout << "Simple sort: ";
	sort(vectorForTest.begin(), vectorForTest.end());
	CheckResults(IsEqual(vectorForTest, vectorShouldBe));
	cout << "One element: ";
	vectorForTest.erase(vectorForTest.begin(), vectorForTest.end());
	vectorForTest.push_back(3);
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
	vecForTest.erase(vecForTest.begin(), vecForTest.end());
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

void TestAccumulate()
{
	//summ
	vector<int> vecForTest;
	vecForTest.push_back(0);
	vecForTest.push_back(5);
	vecForTest.push_back(10);
	vecForTest.push_back(20);
	cout << "Simple check sum: ";
	CheckResults(accumulate(vecForTest.begin(), vecForTest.end(), 0) == 35);
	cout << "No elements sum: ";
	vecForTest.erase(vecForTest.begin(), vecForTest.end());
	CheckResults(accumulate(vecForTest.begin(), vecForTest.end(), 0) == 0);
	cout << "One elements sum: ";
	vecForTest.push_back(5);
	CheckResults(accumulate(vecForTest.begin(), vecForTest.end(), 0) == 5);
	//multiplication
	vecForTest.erase(vecForTest.begin(), vecForTest.end());
	vecForTest.push_back(0);
	vecForTest.push_back(5);
	vecForTest.push_back(10);
	vecForTest.push_back(20);
	cout << "Simple check mult: ";
	CheckResults(accumulate(vecForTest.begin(), vecForTest.end(), 1, multiplies<int>()) == 0);
	cout << "No elements mult: ";
	vecForTest.erase(vecForTest.begin(), vecForTest.end());
	CheckResults(accumulate(vecForTest.begin(), vecForTest.end(), 1, multiplies<int>()) == 1);
	cout << "One elements is 0 mult: ";
	vecForTest.push_back(5);
	CheckResults(accumulate(vecForTest.begin(), vecForTest.end(), 0, multiplies<int>()) == 0);
}

void TestTransform()
{
  vector<int> test1;
  vector<int> checked1;
  vector<int> checked;
  for(int i = 1; i < 5; i++) 
  {
	test1.push_back (i * i);                    // test1: 1 4 9  16 
	checked1.push_back (i * i);
  }
 
  //vector<int> test2(test1.size());
  //transform(test1.begin(), test1.end(), test2.begin(), [](int i){return ++i;});       // test2: 2 5 10 17

  vector<int> test2p;
  transform(test1.begin(), test1.end(), back_inserter(test2p), [](int i){return ++i;});       // test2: 2 5 10 17


  cout << "Unary operation, the first is the same: ";
  checked.push_back(2);
  checked.push_back(5);
  checked.push_back(10);
  checked.push_back(17);
  CheckResults(IsEqual(test1, checked1));
  cout << "Unary operation, the second has changed: ";
  CheckResults(IsEqual(test2p, checked));

  cout << "Binary operation, the first is the same: ";
  checked.erase(checked.begin(), checked.end());
  checked.push_back(3);
  checked.push_back(9);
  checked.push_back(19);
  checked.push_back(33);
  transform(test1.begin(), test1.end(), test2p.begin(), test2p.begin(), [](int i, int j){return i + j;}); // test1: 3 9 19 33 
  CheckResults(IsEqual(test1, checked1));   
  cout << "Binary operation, the second has changed: ";
  CheckResults(IsEqual(test2p, checked));

  cout << "No elements: ";
  test1.erase(test1.begin(), test1.end());
  checked.erase(checked.begin(), checked.end());
  test2p.erase(test2p.begin(), test2p.end());
  transform(test1.begin(), test1.end(), test2p.begin(),[](int i){return ++i;});
  CheckResults(IsEqual(test2p, checked));
 }

int _tmain(int argc, _TCHAR* argv[])
{
	argc;argv;
	cout << "\nSORT\n";
	TestSort();
	cout << "\nFIND\n";
	TestFind();
	cout << "\nBINARY_SEARCH\n";
	TestBinarySearch();
	cout << "\nFOR_EACH\n";
	TestForEach();
	cout << "\nACCUMULATE\n";
	TestAccumulate();
	cout << "\nTRANSFORM\n";
	TestTransform();
	cin.get();
	return 0;
}



