#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sys/time.h>

using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int len = nums.size();
		for(int i = 0; i < len;) {
			if(nums[i] == val) {
				nums[i] = nums[--len];
			}else {
				i++;
			}
		}
		return len;
	}
};

int main()
{
	struct timeval start;
	struct timeval end;
	unsigned long time;

	vector<int> input = {3,2,2,3};
	Solution s;


	gettimeofday(&start,NULL);

	/*****************************************/

	int res = s.removeElement(input, 3);	

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
