class Solution {
public:
    int fpow(int a, int b) // DFS
    {
        if (!b) {
            return 1;
        }
        long long p = fpow(a, b >> 1);
        if (b & 1) {
            return ((p % 1000000007) * (p % 1000000007) * (a % 1000000007)) %
                   1000000007;
        } else {
            return ((p % 1000000007) * (p % 1000000007)) % 1000000007;
        }
    }
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        int md = 1000000007;
        for (int i = 0; i < n; i++) {
            int idx = upper_bound(nums.begin() + i + 1, nums.end(),
                                  target - nums[i]) -
                      nums.begin();
            idx--;
            if (idx >= i && nums[idx] + nums[i] <= target) {
                ans += fpow(2, idx - i) % md;
                ans %= md;
            }
        }
        return ans;
    }
};