#include <iostream>
#include <stack>
using namespace std;
void SortStack(std::stack<int>& in)
{
	stack<int> tmp, out;
	out.push(in.top());
	in.pop();
	while(!in.empty())
	{
		stack<int> i; 
		i.push(in.top());
		in.pop();
		while(!i.empty())
		{
			//find right place
			if(out.empty() ||  (i.top() < out.top()))
			{
				out.push(i.top());
				i.pop();
			}
			else
			{
				tmp.push(out.top());
				out.pop();
			}
		}
		while(!tmp.empty())
		{
			//put all elements back to out;
			out.push(tmp.top());
			tmp.pop();
		}
	}
	in = out;
}
	
void PrintStack(std::stack<int> stackIn)
{
	while(!stackIn.empty())
	{
		std::cout << stackIn.top() << " ";
		stackIn.pop();
	}
	std::cout << "\n";
}

int main() {
	// your code goes here
	std::stack<int> st;
	st.push(2);
	st.push(9);
	st.push(5);
	st.push(10);
	PrintStack(st);
	SortStack(st);
	PrintStack(st);
	return 0;
}