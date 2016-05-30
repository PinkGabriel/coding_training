#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

 /*
class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> arr;
        for(auto i:num)
            arr.push_back(to_string(i));
        sort(begin(arr), end(arr), [](string &s1, string &s2){ return s1+s2>s2+s1; });
        string res;
        for(auto s:arr)
            res+=s;
        while(res[0]=='0' && res.length()>1)
            res.erase(0,1);
        return  res;
    }
};
// */

class Solution { 
public:
string largestNumber(vector<int> &num) {
    string result;
    vector<string> str;
    for (auto n : num) {
        str.push_back(to_string(n));
    }
    sort(str.begin(), str.end(), compareNum);
    for (auto s: str) {
        result += s;
    }

    int pos = 0;
    while (result[pos] == '0' && pos + 1 < result.size()) pos++; 
    return result.substr(pos);
} 
private:
static bool compareNum(string a, string b) {
    return a + b > b + a;
}
};

int main()
{
	vector<int> num = {3, 30, 34, 5, 9};
	Solution s;
	string res = s.largestNumber(num);
	cout << res << endl;
	return 0;
}
