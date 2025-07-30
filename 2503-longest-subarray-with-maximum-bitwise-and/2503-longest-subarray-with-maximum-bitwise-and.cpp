class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        int i = 0;
        int l = 0;
        while (i < n) {
            int j = i;
            while (j < n && nums[j] == mx) {
                j++;
            }
            l = max(l, j - i);
            if (j == i) {
                i++;
            } else {
                i = j;
            }
        }
        return l;
    }
};