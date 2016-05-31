#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

class Solution {
public:
	bool isPowerOfFour(int num) {
	//fs/ext2/balloc.c" 1500 lines	
	//
	//	内核中判断num是不是x的幂,效率也不高嘛=.=
	//        int x = 3/5/7/...;
	//
	//        while (num > x)
	//        	x *= 3/5/7/...;
	//        return num == x;
	//
	

	 /*
	        if(num == 0) {
			return false;
		}
		if(num == pow(4, int(log(num)/log(4)))) {
			return true;
		}else {
			return false;
		}
	// */
	
		return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
	}
};

int main()
{
	Solution s;
	int i;
	cin >> i;
	bool flag = s.isPowerOfFour(i);
	cout << flag << endl;
	return 0;
}
