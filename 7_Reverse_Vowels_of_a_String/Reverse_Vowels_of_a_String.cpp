#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<unordered_set>

using namespace std;

class Solution {
public:
	string reverseVowels(string s) {
		string res = s;
		if(s.empty()) {
			return res;
		}
		unordered_set<char> vow= {'a', 'e', 'i', 'o', 'u'};
		stack<char> stk;
		queue<string::iterator> que;
		for(auto i = res.begin(); i != res.end(); i++) {
			if(vow.count(*i)) {
				stk.push(*i);
				que.push(i);
			}
		}
		while(!stk.empty()) {
			*que.front() = stk.top();
			que.pop();
			stk.pop();
		}
		return res;
	}
};

int main()
{
	string input = "abcdefg";
	Solution s;
	string res = s.reverseVowels(input);
	cout << res << endl;
	return 0;
}
