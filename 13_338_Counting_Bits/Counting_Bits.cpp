#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<int> countBits(int num) {
	 /*
		vector<int> res;
		for(int i  = 0; i <= num; i++) {
			int temp = i, count = 0;
			while(temp) {
				if(temp % 2) {
					count++;
				}
				temp = temp >> 1;
			}
			res.push_back(count);
		}
		return res;
	// */
	/*************************************************/
		// i&(i-1)去掉了最左边的一个1，即1的个数少一个。
		        vector<int> ret(num+1, 0);
			for (int i = 1; i <= num; ++i)
				ret[i] = ret[i&(i-1)] + 1;
				//ret[i] = ret[i >> 1] + (i & 1);
			return ret;
	}
};

int main()
{
	int num = 5;
	Solution s;
	vector<int> res = s.countBits(num);
	for(int i:res) {
		cout << i << endl;
	}
	return 0;
}
