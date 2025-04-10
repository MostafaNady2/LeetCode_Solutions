class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // Unique(nums);
        sort(nums.begin(), nums.end());
        nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
        int n = nums.size(), ans = -1;
        if (nums[0] < k) {
            return -1;
        }
        int idx = upper_bound(nums.begin(), nums.end(), k) - nums.begin();
        if (idx == n) {
            if(nums[0]!=k){
                return -1;
            }else{
                return 0;
            }
        } else {
            return n - idx;
        }
        return -1;
    }
};