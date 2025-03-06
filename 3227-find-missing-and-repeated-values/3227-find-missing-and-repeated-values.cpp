class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> arr;
        arr.resize((n * n) + 1, 0);
        int num;
        long long sum=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sum += grid[i][j];
                arr[grid[i][j]]++;
                if (arr[grid[i][j]] > 1) {
                    num = grid[i][j];
                    sum -= grid[i][j];
                }
            }
        }
        n *= n;
        long long all = n * (n + 1) / 2;
        int missed = all - sum;
        vector<int> v(2);
        v[0] = num;
        v[1] = missed;
        return v;
    }
};