class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int arr[32];
        memset(arr, 0, sizeof(arr));
        int n = nums.size(), ptr1 = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 32; j++) {
                arr[j] += ((nums[i] >> j) & 1);
            }
            for (int j = 0; j < 32; j++) {
                while (arr[j] > 1) {
                    for (int k = 0; k < 32; k++) {
                        arr[k] -= ((nums[ptr1] >> k) & 1);
                    }
                    ptr1++;
                }
            }
            ans = max(ans, i - ptr1 + 1);
        }
        return ans;
    }
};