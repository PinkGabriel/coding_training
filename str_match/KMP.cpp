#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sys/time.h>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0, j = 0, p = needle.size(), t = haystack.size();
        if(p == 0) return 0;
        if(t == 0) return -1;
        vector<int> nextval(next(needle));
        while(i < p && j < t) {
            if(i == -1 || needle[i] == haystack[j]) {
                i++;
                j++;
            }else {
                i = nextval[i];
            }
        }
        if(i == p) {
            return j - p;
        }else {
            return -1;
        }
    }
private:
    vector<int> next(string &pattern) {
        int i = 0, j = -1, n = pattern.size();
        vector<int> nextval(n);
        nextval[0] = -1;
        while(i < n - 1) {
            if(j == -1 || pattern[i] == pattern[j]) {
                i++;
                j++;
                if(pattern[i] != pattern[j]) {
                    nextval[i] = j;
                }else {
                    nextval[i] = nextval[j];
                }
            }else {
                j = nextval[j];
            }
        }
        return nextval;
    }
};

int main()
{
	struct timeval start;
	struct timeval end;
	unsigned long time;
	string text = "abcdefghi";
	string pattern = "def";

	Solution s;
	int res = s.strStr(text, pattern);

	gettimeofday(&start,NULL);

	/*****************************************/

	

	/*****************************************/

	gettimeofday(&end,NULL);

	cout << "index: " << res << endl;

	time = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
	cout << "runtime: " << time << " ums" << endl;
	return 0;
}
