#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<sys/time.h>

using namespace std;

class Solution {
public:


vector<vector<int> > threeSum(vector<int> &num) {

    vector<vector<int> > res;

    std::sort(num.begin(), num.end());

    for (int i = 0; i < num.size(); i++) {

        int target = -num[i];
        int front = i + 1;
        int back = num.size() - 1;

        while (front < back) {

            int sum = num[front] + num[back];

            // Finding answer which start from number num[i]
            if (sum < target)
                front++;

            else if (sum > target)
                back--;

            else {
                vector<int> triplet(3, 0);
                triplet[0] = num[i];
                triplet[1] = num[front];
                triplet[2] = num[back];
                res.push_back(triplet);
                while (front < back && num[front] == triplet[1]) front++;
                while (front < back && num[back] == triplet[2]) back--;
            }

        }
        while (i + 1 < num.size() && num[i + 1] == num[i]) 
            i++;

    }

    return res;

}


	 /*
	vector<vector<int> > threeSum(vector<int>& nums) {
		vector<vector<int> > res;
		vector<int> temp;
		unordered_map<int, int> p,n;
		int zero_count = 0;
		for(int i:nums) {
			if(i > 0) {
				p[i]++;
			} else if(i < 0) {
				n[i]++;
			}else {
				zero_count++;
			}
		}
		// 0 0 0
		if(zero_count >= 3) {
			temp = {0,0,0};
			res.push_back(temp);
		}
		// - 0 +
		if(zero_count) {
			for(auto i:p) {
				if(n[-i.first]) {
					temp = {-i.first, 0, i.first};
					res.push_back(temp);
				}
			}
		}
		// - - + / - + +
		for(auto i:p) {
			for(auto j:n) {
				int target = -(i.first + j.first);
				if(target) {
				if(n.find(target) != n.end()) {
					if(target < j.first) {
						temp = {target, j.first, i.first};
						res.push_back(temp);
					}else if(target > j.first) {
						temp = {j.first, target, i.first};
						res.push_back(temp);
					}else {
						if(j.second > 1) {
							temp = {j.first, target, i.first};
							res.push_back(temp);
						}
					}
					continue;
				}
				if(p.find(target) != p.end()) {
					if(target < i.first) {
						temp = {j.first, target, i.first};
						res.push_back(temp);
					}else if(target > i.first) {
						temp = {j.first, i.first, target};
						res.push_back(temp);
					}else {
						if(i.second > 1) {
							temp = {j.first, target, i.first};
							res.push_back(temp);
						}
					}
					continue;
				}
				}
			}
		}
		return res;
	}
	// */
};

int main()
{
	struct timeval start;
	struct timeval end;
	unsigned long time;

	vector<int> input = {-1,0,1,2,-1,-4};
	//vector<int> input = {3,-2,1,0};
	Solution s;
	vector<vector<int> > res;


	gettimeofday(&start,NULL);

	/*****************************************/

	res = s.threeSum(input);
	for(auto i:res) {
		for(auto j:i)
			cout << j << ' ';
		cout << endl;
	}

	/*****************************************/

	gettimeofday(&end,NULL);

	time = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
	cout << "runtime: " << time << " ums" << endl;
	return 0;
}
