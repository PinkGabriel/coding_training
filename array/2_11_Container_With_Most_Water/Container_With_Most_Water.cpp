#include<iostream>
#include<vector>
#include<sys/time.h>

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		 /*
		int max = 0;
		for(int i = 0; i < height.size() - 1; i++) {
			for(int j = i + 1; j < height.size(); j++) {
				int temp = min(height[j], height[i]) * (j - i);
				//int temp = (height[i] > height[j] ? height[j] : height[i]) * (j - i);
				if(temp > max) {
					max = temp;
				}
			}
		}
		return max;
		// */
		int water = 0;
		int i = 0, j = height.size() - 1;
		while (i < j) {
			int h = min(height[i], height[j]);
			water = max(water, (j - i) * h);
			while (height[i] <= h && i < j) i++;
			while (height[j] <= h && i < j) j--;
		}
	        return water;
	}
};

int main()
{
	struct timeval start;
	struct timeval end;
	unsigned long time;

	vector<int> input = {1,99,100,4,4,4,3,2,1};
	Solution s;


	gettimeofday(&start,NULL);

	/*****************************************/

	int max = s.maxArea(input);
	cout << max << endl;

	/*****************************************/

	gettimeofday(&end,NULL);

	time = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
	cout << "runtime: " << time << " ums" << endl;
	return 0;
}
