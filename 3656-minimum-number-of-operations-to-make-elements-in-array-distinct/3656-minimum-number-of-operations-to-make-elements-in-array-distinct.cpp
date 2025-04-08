class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int arr[101] = {0};
        fill(arr, arr + 101, 0);
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (arr[nums[i]]) {
                return (i + 3) / 3;
            }
            arr[nums[i]]++;
        }
        return 0;
    }
};