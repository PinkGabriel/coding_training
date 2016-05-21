#include<iostream>
#include<vector>
#include<cstdlib>
#include<fstream>
using namespace std;

int main()
{
	int random = 100;
	int r;
	string str1,str2,str3;
	ifstream infile("input.txt");
	vector<int> v(8);
	v[0] = 1;

	srand(time(NULL));
	r = rand() % random;
	cout << v[0] << '\n' << r << '\n';
	if (!infile)
		cerr << "error\n";
	else
		infile >> str1 >> str2 >> str3;
	cout << str1 << str2 << str3;
	return 0;
}
