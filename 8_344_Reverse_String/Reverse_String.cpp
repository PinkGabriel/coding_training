#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
	string reverseString(string s) {
		string res;
		if(s.empty()) {
			return res;
		}
		for(auto i = s.rbegin(); i != s.rend(); i++) {
			res += *i;
		}
		return res;
	}
};

int main()
{
	string str = "hello";
	Solution s;
	string res = s.reverseString(str);
	cout << res << endl;
	return 0;
}
