class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int curr = 0, pre = 0, ans = 0;
        int cnt = 0;
        bool z = false;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                int c = 0, j = i;
                while (j < n && nums[j] == 0) {
                    j++;
                    c++;
                }
                i = j - 1;
                if (c > 1) {
                    ans = max(ans, curr + pre);
                    pre = 0;
                    curr = 0;
                    cnt = 0;
                    continue;
                }
                ans = max(ans, curr + pre);
                pre = curr;
                cnt = 0;
            } else {
                cnt++;
                curr = cnt;
            }
        }
        if (nums.back() != 0) {
            ans = max(ans, pre + cnt);
            if (ans == n) {
                return n - 1;
            }
        }
        return ans;
    }
};