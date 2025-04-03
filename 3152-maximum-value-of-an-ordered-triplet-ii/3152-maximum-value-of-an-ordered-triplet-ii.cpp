class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) // ( a - b ) * c
    {
        int n = nums.size();
        vector<int> suff(n, 0), pre(n, 0);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre[i] = max(nums[i], pre[i - 1]);
        }
        suff[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suff[i] = max(nums[i], suff[i + 1]);
        }
        long long ans = 0;

        for (int i = 1; i < n - 1; i++) {
            ans = max(ans, (long long)(pre[i - 1] - nums[i]) * suff[i + 1]);
        }
        return max(ans, 0LL);
    }
};