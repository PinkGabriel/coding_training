#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main()
{
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
	return 0;
}
