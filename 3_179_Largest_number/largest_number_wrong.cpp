#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

class Solution {
public:
	string largestNumber(vector<int>& nums) {
		int n = nums.size();
		string res;
		if(nums.empty()) {
			return res;
		}
		vector<pair<int, int> > p;
		int max = 1; //最大位数
		for(int i = 0; i < n; i++) {
			int j = 1;
			while(nums[i] >= pow(10, j)) j++;
			p.push_back(make_pair(nums[i],j));
			if(j > max) {
				max = j;
			}
		}
		for(int i = 0; i < n; i++) {
			int temp = p[i].first;
			p[i].first = temp * pow(10, max - p[i].second);
			p[i].second = temp;
		}
		quick_sort(p, 0, n - 1);
		//insertion_sort(p);
		for(int i = 0; i < n; i++) {
			res += to_string(p[i].second);
		}
	}
private:
	/*
	void insertion_sort(vector<pair<int, int> > pair)
        {
            for (int i = 1; i < pair.size(); i++)
            {
                if (unsorted[i - 1] > unsorted[i])
                {
                    pair<int, int> temp = unsorted[i];
                    int j = i;
                    while (j > 0 && unsorted[j - 1] > temp)
                    {
                        unsorted[j] = unsorted[j - 1];
                        j--;
                    }
                    unsorted[j] = temp;
                }
            }
        }
	*/

	// /*
	void quick_sort(vector<pair<int, int> >& vpair, int p, int r) {
		if (p < r) {  
			int q = partition (vpair, p, r);  
			quick_sort (vpair, p, q - 1);  
			quick_sort (vpair, q + 1, r);  
		} 
	}

	int partition(vector<pair<int, int> >& vpair, int p, int r)  
	{  
		int i = p - 1;  
		for (int j = p; j < r; j++) {  
			if (vpair[j].first > vpair[r].first ||
				(vpair[j].first == vpair[r].first && vpair[j].second < vpair[r].second)) {  
				swap(vpair, ++i, j);  
			}  
		}
		swap(vpair, ++i, r);  
		return i;  
	}
	void swap(vector<pair<int, int> >& p, int a, int b) {
		pair<int, int> temp = p[a];
		p[a]= p[b];
		p[b] = temp;
	}
	// */

};

int main()
{
	vector<int> num = {3, 30, 34, 5, 9};
	Solution s;
	string res = s.largestNumber(num);
	cout << res << endl;
	return 0;
}
