#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sys/time.h>

using namespace std;

class Solution {
public:
	string reverseVowels(string s) {
		
	}
};

int main()
{
	struct timeval start;
	struct timeval end;
	unsigned long time;

	vector<int> res = {0};
	Solution s;


	gettimeofday(&start,NULL);

	/*****************************************/

	

	/*****************************************/

	gettimeofday(&end,NULL);

	time = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
	cout << "runtime: " << time << " ums" << endl;
	return 0;
}
