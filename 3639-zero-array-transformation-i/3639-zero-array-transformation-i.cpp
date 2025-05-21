class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        const int n = nums.size();
        int m = queries.size();
        vector<int> arr(n+1,0);
        for (int i = 0; i < m; i++) {
            arr[queries[i][0]]--;
            arr[queries[i][1] + 1]++;
        }
        for (int i = 1; i < n; i++) {
            arr[i] += arr[i - 1];
        }
        for (int i = 0; i < n; i++) {
            if (arr[i] + nums[i] > 0) {
                return false;
            }
        }
        return true;
    }
};