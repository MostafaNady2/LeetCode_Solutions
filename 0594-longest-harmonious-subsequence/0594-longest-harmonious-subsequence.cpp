class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            bool f = false;
            while (j < n && nums[j] - nums[i] <= 1) {
                if (nums[j] - nums[i] == 1) {
                    f = true;
                }
                j++;
            }
            if (f) {
                ans = max(ans, j - i);
            }
        }
        return ans;
    }
};