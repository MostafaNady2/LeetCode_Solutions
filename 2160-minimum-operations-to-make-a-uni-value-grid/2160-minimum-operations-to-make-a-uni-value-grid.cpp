class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> arr;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr.push_back(grid[i][j]);
            }
        }
        sort(arr.begin(), arr.end());
        int mid = arr[arr.size() / 2];
        long long sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            if ((arr[i] - arr[0]) % x != 0) {
                return -1;
            }
            sum += abs(arr[i] - mid) / x;
        }
        return sum;
    }
};