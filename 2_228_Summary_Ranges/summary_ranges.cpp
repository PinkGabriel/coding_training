#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> result;
		if(nums.empty()) {
			cerr << "vector empty" << endl;
			return result;
		}
		int start = nums[0], end = nums[0];
		for(int i = 1; i < nums.size(); i++) {
			if(nums[i] != (nums[i - 1] + 1)) {
				emit(start, end, result);
				start = nums[i];
				end = nums[i];
			}else {
				end = nums[i];
			}
		}
		emit(start, end, result);
	}
private:
	void emit(int start, int end, vector<string> &result) {
		stringstream stream;
		string str;
		if(start == end) {
			stream << start;
			str = stream.str();
		//	cout << str << endl;
			result.push_back(str);
		}else {
			stream << start << "->" << end;
			str = stream.str();
		//	cout << str << endl;
			result.push_back(str);
		}
	}
};

class Solution1 {
	public:
		vector<string> summaryRanges(vector<int>& nums) {
			const int size_n = nums.size();
			vector<string> res;
			if ( 0 == size_n) return res;
			for (int i = 0; i < size_n;) {
				int start = i, end = i;
				while (end + 1 < size_n && nums[end+1] == nums[end] + 1) end++;
				if (end > start) res.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
				else res.push_back(to_string(nums[start]));
				i = end+1;
			}
			return res;
		}
};

int main()
{
	Solution inst;
	Solution1 inst1;
	vector<string> result;
	int a[6] = {0,1,2,4,5,7};
	vector<int> v(a, a + 6);
	result = inst1.summaryRanges(v);
	// /*
	for(int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
	// */
	return 0;
}
