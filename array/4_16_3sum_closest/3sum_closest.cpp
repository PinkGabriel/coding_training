class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min = nums[0] + nums[1] + nums[2] - target, delta;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1, k = nums.size() - 1;
            while(j < k) {
                delta = nums[i] + nums[j] + nums[k] - target;
                if(delta == 0) {
                    return target;
                }else if(delta > 0){
                    while(j < k && nums[k] == nums[k-1]) k--;
                    k--;
                }else {
                    while(j < k && nums[j] == nums[j+1]) j++;
                    j++;
                }
                if(abs(delta) < abs(min)) {
                    min = delta;
                }
            }
        }
        return (target + min);
    }
};
