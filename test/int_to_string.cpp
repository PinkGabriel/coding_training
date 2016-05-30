#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main()
{
	//stringstream
	int i = 10;
	string str;
	string str1;
	stringstream stream;
	stream << i;
	str = stream.str();
	str += "->";
	cout << str <<endl;

	stream << "->" << i;
	str1 = stream.str();
	cout << str1 <<endl;
	
	//to_string need c++11
	//compile: g++ -std=c++11 int_to_string.cpp
	string pi = "pi is " + to_string(3.1415926);
	cout << pi << '\n';
	
	return 0;
}
