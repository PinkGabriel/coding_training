#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sys/time.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    if (m > n) return findMedianSortedArrays(nums2, nums1);
    int low = 0, high = m, half = (m + n) / 2, odd = (m + n) % 2;
    while(low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = half - cut1;
        if(cut1 == 0 || cut1 == m) {
            if(cut1 == 0 && nums1[0] < nums2[cut2 - 1]) {
		cut1 = 1;
                cut2 = half - cut1;
		swap(nums1[0], nums2[cut2 - 1]);
		//cout << nums1[0] << ' ' << nums2[cut2 - 1] << endl;
            }
            if(odd) {
                return double(nums2[cut2]);
            }else {
                if(m == n) {
                    return double(max(nums1[0], nums2[0]) + min(nums1[m-1], nums2[n-1])) / 2;
                }else {
                    return double(nums2[cut2 - 1] + nums2[cut2]) / 2;    
                }
            }
       }

        if(nums1[cut1 - 1] <= nums2[cut2] && nums2[cut2 - 1] <= nums1[cut1]) {
            if(odd) {
                return double(min(nums1[cut1], nums2[cut2])); 
            }else {
                return double(max(nums1[cut1 - 1], nums2[cut2 - 1]) + min(nums1[cut1], nums2[cut2])) / 2;
            }
        }else if(nums1[cut1 - 1] > nums2[cut2]){
            high = cut1 - 1;
        }else {
            low = cut1 + 1;
        }
    }
    return 0;
  }
};

int main()
{
	struct timeval start;
	struct timeval end;
	unsigned long time;

	vector<int> num1 = {2};
	vector<int> num2 = {1,3,4};
	Solution s;


	gettimeofday(&start,NULL);

	/*****************************************/

	double res = s.findMedianSortedArrays(num1, num2);

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
