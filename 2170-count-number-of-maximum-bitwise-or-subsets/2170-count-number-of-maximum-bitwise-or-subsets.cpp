class Solution {
public:
    int maxSub(vector<int>& v, int idx, int sor) {
        if (idx == v.size()) {
            return sor;
        }
        return max(maxSub(v, idx + 1, (sor | v[idx])), maxSub(v, idx + 1, sor));
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int mx = maxSub(nums, 0, 0);
        int ans = 0;
        for (int i = 0; i < (1 << nums.size()); i++) {
            int sor = 0;
            for (int j = 0; j < nums.size(); j++) {
                if ((i >> j) & 1) {
                    sor |= nums[j];
                }
            }
            if (mx == sor) {
                ans++;
            }
        }
        return ans;
    }
};