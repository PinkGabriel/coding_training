#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sys/time.h>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        if(nums.size() < 4) {
            return res;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 3; i++) {
            for(int j = i + 1; j < nums.size() - 2; j++) {
                int aim = target - nums[i] - nums[j];
                int k = j + 1, l = nums.size() - 1;
                while(k < l) {
                    int sum = nums[k] + nums[l];
                    if(sum == aim) {
                        vector<int> quad = {nums[i],nums[j],nums[k],nums[l]};
                        res.push_back(quad);
                        while(k < l && nums[k] == nums[k+1]) k++;
			k++;
                        while(k < l && nums[l] == nums[l-1]) l--;
			l--;
                    }else if(sum > aim) {
                        while(k < l && nums[l] == nums[l-1]) l--;
			l--;
                    }else {
                        while(k < l && nums[k] == nums[k+1]) k++;
			k++;
                    }
                }
                while(nums[j] == nums[j+1]) { j++; };
            }
            while(nums[i] == nums[i+1]) { i++; };
        }
        return res;
    }
};

int main()
{
	struct timeval start;
	struct timeval end;
	unsigned long time;

	vector<int> input = {-5,-1,-1,0,2,2,4};
	Solution s;


	gettimeofday(&start,NULL);

	/*****************************************/

	vector<vector<int> > res = s.fourSum(input,3);

	/*****************************************/

	gettimeofday(&end,NULL);

	for(auto i:res) {
		for(auto j:i) {
			cout << j << ' ';
		}
		cout << endl;
	}

	time = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
	cout << "runtime: " << time << " ums" << endl;
	return 0;
}
