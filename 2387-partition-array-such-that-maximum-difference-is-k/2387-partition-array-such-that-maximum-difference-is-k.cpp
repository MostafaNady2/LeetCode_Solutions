class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 1;
        sort(nums.begin(), nums.end());
        int mn = nums[0];
        for (int i = 0; i < n; i++) {
            if (nums[i] - mn > k) {
                ans++;
                mn = nums[i];
            }
        }
        return ans;
    }
};