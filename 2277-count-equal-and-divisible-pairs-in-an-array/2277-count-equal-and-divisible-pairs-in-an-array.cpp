class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((i * j) % k == 0 && nums[i] == nums[j] && i != j) {
                    ans++;
                }
            }
        }
        return ans/2;
    }
};