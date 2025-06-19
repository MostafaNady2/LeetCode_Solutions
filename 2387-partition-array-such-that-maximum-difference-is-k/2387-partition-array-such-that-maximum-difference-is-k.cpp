class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 1, mn = nums[0];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (nums[i] - mn > k) {
                ans++;
                mn = nums[i];
            } else {
                mn = min(mn, nums[i]);
            }
        }
        return ans;
    }
};