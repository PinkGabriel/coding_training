#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

class Solution {
public:
	 /*
	int integerBreak(int n) {
		int max = 0;
		for(int i = 2; i <= n; i++) {
			int re = n % i;
			int multi = n / i;
			int temp = 1;
			for(int j = 0; j < (i - re); j++) {
				temp *= multi;
			}
			for(int j = 0; j < re; j++) {
				temp *= (multi + 1);
			}
			if(temp > max) {
				max = temp;
			}
		}
		return max;
	}
	// */
	int integerBreak(int n) {
	        if(n==2) return 1;
		if(n==3) return 2;
		int product = 1;
		while(n>4){
			product*=3;
			n-=3;
		}
		product*=n;
		return product;
	}
};

int main()
{
	int n;
	Solution s;
	cout << "input n :" << endl;
	cin >> n;
	int res = s.integerBreak(n);
	cout << res << endl;
	return 0;
}
