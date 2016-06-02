#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<sys/time.h>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		 /* wrong.
		vector<int> res;
		for(int i = 0; i < nums.size(); i++) {
		//for(int i = 0; i < nums.size() - 1; i++) {
			for(int j = i + 1; j < nums.size(); j++) {
				if(nums[i] + nums[j] == target) {
					res.push_back(i);
					res.push_back(j);
				}
			}
		}
		return res;
		// */

		vector<int> res;
		unordered_map<int, int> m;
		for(int i = 0; i < nums.size(); i++) {
			int p = target - nums[i];
			if(m.find(p) != m.end()) {
				res.push_back(m[p]);
				res.push_back(i);
				break;
			}
			m[nums[i]] = i;
		}
		return res;
	}
};

int main()
{
	struct timeval start;
	struct timeval end;
	unsigned long time;

	vector<int> input = {2, 7, 11, 15};
	int target = 9;
	Solution s;


	gettimeofday(&start,NULL);
	vector<int> res = s.twoSum(input, target);
	gettimeofday(&end,NULL);

	time = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
	cout << "runtime: " << time << " ums" << endl;
	for(auto i:res) {
		cout << i << ' ';
	}
	cout << endl;
	return 0;
}
