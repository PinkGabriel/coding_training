#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	string s = "gfedcba";
	sort(s.begin(), s.end());
	for(char i:s) {
		cout << i << endl;
	}
	return 0;
}
