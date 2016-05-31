#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		vector<int> res;
		if(nums.empty()) {
			return res;
		}
		map<int, int> m;
		for(auto i:nums) {
			m[i]++;
		}

		multimap<int, int, greater<int> > n;
		map<int, int>::iterator iter = m.begin();
		for(; iter != m.end(); iter++) {
			n.insert(make_pair(iter->second,iter->first));
		}
		multimap<int, int>::iterator miter = n.begin();
		for(int i = 0; i < k; i++,miter++) {
			res.push_back(miter->second);
		}
		return res;
	}
};

int main()
{
	vector<int> nums = {1,2};
	Solution s;
	vector<int> res = s.topKFrequent(nums,2);
	for(auto i:res) {
		cout << i << endl;
	}
	return 0;
}
