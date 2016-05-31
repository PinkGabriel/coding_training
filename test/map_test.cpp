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
	cout << "if not exist: " << m[1] << " ." <<endl;
	m[1]++;
	cout << "if not exist: " << m[1] << " ." <<endl;
	return 0;
}
