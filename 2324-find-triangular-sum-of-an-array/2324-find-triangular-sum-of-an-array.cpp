class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        int arr[n];
        for (int i = 0; i < n; i++) {
            arr[i] = nums[i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                arr[j] = (arr[j] + arr[j + 1]) % 10;
            }
        }
        return arr[0];
    }
};