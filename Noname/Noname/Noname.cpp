// Noname.cpp : Defines the entry point for the console application.
// 
// #include <stdafx.h>
// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// 
// using namespace std;
// int insertionSort(vector<int>&  ar) 
// {  int x = 0;
// for (int i = 1; i < ar.size(); ++i)
// {
// 	for (int k = i; k > 0 && ar[k] < ar[k-1]; --k) 
// 	{
// 		std::swap(ar[k], ar[k-1]);   
// 		++x;
// 	} 
// }
// return x;
// }
// 
// 
// int main() {
// 	/* Enter your code here. Read input from STDIN. Print output to STDOUT */   
// 	vector <int>  _ar;
// 	int testsNumbers, _ar_size;
// 	cin >> testsNumbers;
// 	for (int tests = 0; tests < testsNumbers; ++tests)
// 	{   
// 		cin >> _ar_size;
// 		for(int _ar_i=0; _ar_i<_ar_size; ++_ar_i) 
// 		{
// 			int _ar_tmp;
// 			cin >> _ar_tmp;
// 			_ar.push_back(_ar_tmp); 
// 		}
// 		cout << insertionSort(_ar) << "\n";
// 		_ar.clear();
// 	}
// 
// 
// 
// 	return 0;
// }
// 
#include <stdafx.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <regex>
using namespace std;


int main() 
{
	string str1,str2,child;
	cin >> str1;
	cin >>str2;
	size_t max = 0;
	size_t prev1 = 0, prev2 = 0;
	for(int j1 = 0; j1 < str1.size(); ++j1)
	{
		for(size_t i1 = j1; i1 < str1.size(); ++i1)
		{
			auto i2 = str2.find(str1[i1], prev2);
			if(i2 != string::npos)
			{
				child.push_back(str1[i1]);
				prev2 = i2 + 1;
			}
			if (prev2 == str2.size()) 
			{
				break;
			}
		}
		prev2 = 0;
		if (max < child.size()) max = child.size();
		child.clear();
	}

	for(int j1 = 0; j1 < str1.size(); ++j1)
	{
		if ((str2.find(str1[j1]) != string::npos) && (child.find(str1[j1]) == string::npos))
		{
			child.push_back(str1[j1]);
		}
	}
	cout << max;
// 	string str;
// 	str ="A man, a plan, a canal: Panama.";
// 	transform(str.begin(), str.end(), str.begin(), ::tolower);
// 	str.erase(remove_if(str.begin(), str.end(), ::ispunct), str.end());
// 	str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
// 	bool isEqual(true);
// 	auto size = str.length();
// 	for(size_t i = 0; i < size; ++i)
// 	{
// 		if (i != size - i)
// 		{
// 			char before(str[i]);
// 			char after(str[size - 1 - i]);
// 			if (before != after )
// 			{
// 				isEqual = false;
// 			}
// 		}
// 	}
// 	cout << str << " palindrome " << isEqual ;
// 	int rows(0);
// 	
// 	string str1, str2;
// 	cin >> str1 >> str2;
// 	if (str1.size() != str1.size()) cout << "not permutation";
// 	for(int i = 0; i < str1.size(); ++i)
// 	{
// 		auto it = find(str2.begin(), str2.end(), str1[i]);
// 		if(it != str2.end())
// 		{
// 			str2.erase(it);
// 		}
// 	}
// 	if (str2.size() == 0) cout << "permutation";
// 	else cout << "not permutation after";

// 	try 
// 	{
// 		std::regex regFrame1("[A-Z]{5}[0-9]{4}[A-Z]{1}",std::regex_constants::extended );
// 		std::regex regFrame2("[A-Z]{5}[0-9]{4}[A-Z]{1}",std::regex_constants::egrep);
// 		std::regex regFrame3("[A-Z]{5}[0-9]{4}[A-Z]{1}",std::regex_constants::collate);
// 		std::regex regFrame4("[A-Z]{5}[0-9]{4}[A-Z]{1}",std::regex_constants::basic);
// 		std::regex regFrame5("[A-Z]{5}[0-9]{4}[A-Z]{1}",std::regex_constants::ECMAScript);
// 		std::smatch m;
// 		getline(cin, str);
// 		for(int i = 0; i < rows; ++i)
// 		{
// 			getline(cin, str);
// 			cout << str << "\n";
// 			std::regex_search(str, m, regFrame1);
// 			std::cout << " extended match: " << m[0] << '\n';
// 			std::regex_search(str, m, regFrame2);
// 			std::cout << " egrep  match: " << m[0] << '\n';
// 			std::regex_search(str, m, regFrame3);
// 			std::cout << " collate  match: " << m[0] << '\n';
// 			std::regex_search(str, m, regFrame4);
// 			std::cout << " basic match: " << m[0] << '\n';
// 			std::regex_search(str, m, regFrame5);
// 			std::cout << " ESVAC match: " << m[0] << '\n';
// 			if (regex_match(str, regFrame1))
// 			{
// 				cout << "YES" << "\n";
// 			}
// 			else cout << "NO" << "\n";
// 		}
// 	} 
// 
// 	catch (const std::regex_error& e) {
// 		std::cout << "regex_error caught: " << e.what() << '\n';
// 		if (e.code() == std::regex_constants::error_brack) {
// 			std::cout << "The code was error_brack\n";
// 		}
// 	}

	/* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	return 0;
}

