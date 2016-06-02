#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main()
{
	map<int, int> m;
	m[1]++;
	cout << "if not exist: " << m[1] << "." <<endl;
	m[1]++;
	cout << "if not exist: " << m[1] << "." <<endl;

	if(m.find(1) == m.end()) {
		cerr << "not find" << endl;
	} else {
		cout << "find" << endl;
	}

	if(m.find(0) == m.end()) {
		cerr << "not find" << endl;
	} else {
		cout << "find" << endl;
	}

	if(m.find(0) == m.end()) {
		cerr << "not find" << endl;
	} else {
		cout << "find" << endl;
	}

	int i = m[0];

	if(m.find(0) == m.end()) {
		cerr << "not find" << endl;
	} else {
		cout << "find" << endl;
		cout << m[0] << endl;
	}

	return 0;
}
