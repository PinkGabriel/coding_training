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
	cout << "size: " << s.size() << endl;
	s.pop();
	temp = s.top();
	cout << temp << endl;
	temp = s.size();
	cout << "size: " << s.size() << endl;
	s.pop();
	temp = s.top();
	cout << temp << endl;
	temp = s.size();
	cout << "size: " << s.size() << endl;
	s.pop();
	cout << "size: " << s.size() << endl;
	return 0;
}
