#include<iostream>
#include<stack>

using namespace std;

int main()
{
	stack<int> s;
	s.push(2);
	s.push(3);
	s.push(4);
	int temp = s.top();
	cout << temp << endl;

	s.top()++;
	temp = s.top();
	cout << temp << endl;

	s.pop();
	temp = s.top();
	cout << temp << endl;

	return 0;
}
