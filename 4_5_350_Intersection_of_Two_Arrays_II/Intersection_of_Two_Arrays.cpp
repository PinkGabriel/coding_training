#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution {
public:
	 /*
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> res;
		if(nums1.empty() || nums2.empty()) {
			return res;
		}
		map<int, int> m1, m2;
		for(auto i:nums1) {
			m1[i]++;
		}
		for(auto i:nums2) {
			m2[i]++;
		}
		for(auto i:m1) {
			for(auto j:m2) {
				if(i.first == j.first) {
					int count = i.second < j.second ? i.second : j.second;
					for(int k = 0; k < count; k++) {
						res.push_back(i.first);
					}
					break;
				}
			}
		}
		return res;
	}
	// */
	 /*
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> res;
		unordered_map<int, int> m;
		for(auto i:nums1) {
			m[i]++;
		}
		for(auto i:nums2) {
			if(m.find(i) !=  m.end() && (--m[i]) >= 0) {
				res.push_back(i);
			}
		}
		return res;
	}
	// */
	// /* 每个在结果中只需出现一次，这时用set，而且是unordered_set
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> m(nums1.begin(), nums1.end());
		vector<int> res;
		for (auto a : nums2) {
			if (m.count(a)) {
				res.push_back(a);
				m.erase(a);
			}
		}
		return res;
	}
	// */
};

int main()
{
	//vector<int> nums1 = {1,2,2,1};
	//vector<int> nums2 = {2,2};
	vector<int> nums1 = {1};
	vector<int> nums2 = {1};
	Solution s;
	vector<int> res = s.intersect(nums1,nums2);
	for(auto i:res) {
		cout << i <<endl;
	}
	return 0;
}
