// check_algorithms.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <utility>

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

#define CHECK_RESULTS(res) {if (res){cout << "right\n";}else{ cout << "!!!!ACHTUNG!!!! error in line: " << __LINE__;}}

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
	CHECK_RESULTS(IsEqual(vectorForTest, vectorShouldBe));
	cout << "One element: ";
	vectorForTest.erase(vectorForTest.begin(), vectorForTest.end());
	vectorForTest.push_back(3);
	sort(vectorForTest.begin(),vectorForTest.end());
	CHECK_RESULTS(IsEqual(vectorForTest, vectorShouldBe));
	
}

void TestFind()
{
	vector<int> vecForTest;
	vecForTest.push_back(0);
	vecForTest.push_back(5);
	vecForTest.push_back(100);
	vecForTest.push_back(555);
	cout << "Not found: ";
	CHECK_RESULTS((vecForTest.end() == find(vecForTest.begin(), vecForTest.end(), 56)));
	cout << "The first found value: ";
	CHECK_RESULTS((vecForTest.begin()+1 == find(vecForTest.begin(), vecForTest.end(), 5)));
	vecForTest[0] = 555;
	vecForTest[1] = 555;
	vecForTest[2] = 555;
	vecForTest[3] = 555;
	cout << "The first found value in set of similar elements: ";
	CHECK_RESULTS((vecForTest.begin() == find(vecForTest.begin(), vecForTest.end(), 555)));
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
	CHECK_RESULTS(binary_search(vecForTest.begin(), vecForTest.end(), 0));
	cout << "The element, which is not in the set: ";
	CHECK_RESULTS(!binary_search(vecForTest.begin(), vecForTest.end(), 10));
	vecForTest.erase(vecForTest.begin()+1, vecForTest.end());
	cout << "One element: ";
	CHECK_RESULTS(binary_search(vecForTest.begin(), vecForTest.end(), 0));
	cout << "No elements: ";
	vecForTest.erase(vecForTest.begin(), vecForTest.end());
	CHECK_RESULTS(binary_search(vecForTest.begin(), vecForTest.end(), 0));

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
	CHECK_RESULTS((chFE.num == vecForTest.size())&&(chFE.sum == 22));
	cout << " No elements: ";
	vecForTest.erase(vecForTest.begin(), vecForTest.end());
	chFE = for_each(
		vecForTest.begin(), 
		vecForTest.end(), 
		CheckFE());
	CHECK_RESULTS((chFE.num == vecForTest.size())&&(chFE.sum == 0));
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
	CHECK_RESULTS(accumulate(vecForTest.begin(), vecForTest.end(), 0) == 35);
	cout << "No elements sum: ";
	vecForTest.erase(vecForTest.begin(), vecForTest.end());
	CHECK_RESULTS(accumulate(vecForTest.begin(), vecForTest.end(), 0) == 0);
	cout << "One elements sum: ";
	vecForTest.push_back(5);
	CHECK_RESULTS(accumulate(vecForTest.begin(), vecForTest.end(), 0) == 5);
	//multiplication
	vecForTest.erase(vecForTest.begin(), vecForTest.end());
	vecForTest.push_back(0);
	vecForTest.push_back(5);
	vecForTest.push_back(10);
	vecForTest.push_back(20);
	cout << "Simple check mult: ";
	CHECK_RESULTS(accumulate(vecForTest.begin(), vecForTest.end(), 1, multiplies<int>()) == 0);
	cout << "No elements mult: ";
	vecForTest.erase(vecForTest.begin(), vecForTest.end());
	CHECK_RESULTS(accumulate(vecForTest.begin(), vecForTest.end(), 1, multiplies<int>()) == 1);
	cout << "One elements is 0 mult: ";
	vecForTest.push_back(5);
	CHECK_RESULTS(accumulate(vecForTest.begin(), vecForTest.end(), 0, multiplies<int>()) == 0);
}

void TestTransform()
{
  typedef vector<int> Vec;
  Vec test1;
  Vec checked1;
  Vec checked;
  for(int i = 1; i < 5; i++) 
  {
	test1.push_back (i * i);                    // test1: 1 4 9  16 
	checked1.push_back (i * i);
  }

  //vector<int> test2(test1.size());
  //transform(test1.begin(), test1.end(), test2.begin(), [](int i){return ++i;});       // test2: 2 5 10 17

  Vec test2p;
  transform(test1.begin(), test1.end(), back_inserter(test2p), [](int i){return ++i;});       // test2: 2 5 10 17


  cout << "Unary operation, the first is the same: ";
  checked.push_back(2);
  checked.push_back(5);
  checked.push_back(10);
  checked.push_back(17);
  CHECK_RESULTS(IsEqual(test1, checked1));
  cout << "Unary operation, the second has changed: ";
  CHECK_RESULTS(IsEqual(test2p, checked));

  cout << "Binary operation, the first is the same: ";
  checked.clear();
  checked.push_back(3);
  checked.push_back(9);
  checked.push_back(19);
  checked.push_back(33);
  transform(test1.begin(), test1.end(), test2p.begin(), test2p.begin(), [](int i, int j){return i + j;}); // test1: 3 9 19 33 
  CHECK_RESULTS(IsEqual(test1, checked1));   
  cout << "Binary operation, the second has changed: ";
  CHECK_RESULTS(IsEqual(test2p, checked));

  cout << "No elements: ";
  test1.erase(test1.begin(), test1.end());
  checked.erase(checked.begin(), checked.end());
  test2p.erase(test2p.begin(), test2p.end());
  transform(test1.begin(), test1.end(), back_inserter(test2p),[](int i){return ++i;});
  CHECK_RESULTS(IsEqual(test2p, checked));
 }


void TestSortTable()
{
	{
		typedef std::pair<int, int> IntPair;
		typedef std::vector<IntPair> IntVect;
		typedef IntVect::iterator IntVectIter;


		IntVect test;
		IntVect checked;

 		test.push_back(make_pair(10, 0));
		test.push_back(make_pair(9, 1));
		test.push_back(make_pair(3, 2));
		test.push_back(make_pair(3, 3));
		test.push_back(make_pair(5, 4));
		test.push_back(make_pair(5, 5));
		test.push_back(make_pair(5, 6));
		test.push_back(make_pair(1, 7));


		
		checked.push_back( make_pair(1, 7)); 
		checked.push_back( make_pair(3, 2)); 
		checked.push_back( make_pair(3, 3)); 
		checked.push_back( make_pair(5, 4)); 
		checked.push_back( make_pair(5, 5)); 
		checked.push_back( make_pair(5, 6)); 
		checked.push_back( make_pair(9, 1)); 
		checked.push_back( make_pair(10, 0)); 
		
		stable_sort(test.begin(), test.end());


		bool res = std::equal(test.cbegin(), test.cend(), checked.cbegin(),
			[](const IntPair& left, const IntPair& right)->bool
			{
				return (left.first == right.first) && (left.second == right.second);
			}
		);
		CHECK_RESULTS(res);
	}
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
	cout << "\nTABLE SORT\n";
	TestSortTable();
	cin.get();
	return 0;
}
