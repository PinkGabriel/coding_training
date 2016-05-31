#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
// /*
class Solution {
public:
	string largestNumber(vector<int> &num) {
		vector<string> arr;
		for(auto i:num)
			arr.push_back(to_string(i));
		sort(begin(arr), end(arr), [](string s1, string s2){ return s1+s2>s2+s1; });
		string res;
		for(auto s:arr)
			res+=s;
		while(res[0]=='0' && res.length()>1)
			res.erase(0,1);
		return  res;
	}
};
// */

int main()
{
	vector<int> num = {3, 30, 34, 5, 9};
	Solution s;
	string res = s.largestNumber(num);
	cout << res << endl;
	//[](){ cout << "Hello World!" << endl; }();
	return 0;
}
