#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	string s = "abcdefg";
	if(s[s.length()] == '\0') {
		cout << "last letter null" << endl;
	}
	for(char i:s) {
		cout << i << endl;
	}
	cout << "*************************" << endl;
	for(auto i = s.begin(); i != s.end(); i++) {
		cout << *i << endl;
	}
	return 0;
}
