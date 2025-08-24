class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                v.push_back(cnt);
                cnt = 0;
            } else {
                cnt++;
            }
        }
        if (nums.back() != 0) {
            v.push_back(cnt);
            if (v.back() == n) {
                return n - 1;
            }
        }
        int ans = nums[0];
        for (int i = 0; i < v.size() - 1; i++) {
            ans = max(ans, v[i] + v[i + 1]);
        }
        return ans;
    }
};