#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sys/time.h>

using namespace std;

class Solution {
	public:
	int removeDuplicates(vector<int>& nums) {
		int i = 0, j = 0;
		if(nums.size() < 2) {
			return nums.size();
		}
		while(i < nums.size() && nums[i] == nums[i + 1]) i++;
		for(; i < nums.size(); i++, j++) {
			nums[j] = nums[i];
			while(i < nums.size() && nums[i] == nums[i + 1]) i++;
		}   
		return j;
	}   
};


int main()
{
	struct timeval start;
	struct timeval end;
	unsigned long time;

	vector<int> input = {0,0,0,0,0};
	Solution s;


	gettimeofday(&start,NULL);

	/*****************************************/

	int res = s.removeDuplicates(input);

	/*****************************************/

	gettimeofday(&end,NULL);
	cout << res << endl;

 /*
	for(auto i:res) {
		for(auto j:i) {
			cout << j << ' ';
		}
		cout << endl;
		cout << i << endl;
	}
// */

	time = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
	cout << "runtime: " << time << " ums" << endl;
	return 0;
}
