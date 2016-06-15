#include<iostream>
#include<vector>
#include<cstdlib>
#include<climits>
#include<cfloat>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	cout << INT_MIN << endl;
	cout << INT_MAX << endl;
	cout << FLT_MIN << endl;
	cout << FLT_MAX << endl;
	char ch = 'a';
	if(ch == 97) {
		cout << "it's a!";
	}
	cout << (int)ch;
	string str;
	cin >> str;
	int res = atoi(str.c_str());
	cout << res << endl;
	int i = 100;
	int j;
	j = -i;
	cout << j << endl;
	int modtest = -3;
	int c = modtest % 5;
	cout << c << endl;

	return 0;
}
