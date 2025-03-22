class Solution {
public:
    void dfs(int node, vector<bool>& vis, int& count,
             vector<vector<int>>& arr) {
        vis[node] = true;
        count++;
        for (auto i : arr[node]) {
            if (!vis[i]) {
                dfs(i, vis, count, arr);
            }
        }
    }
    bool isComplete(int node, vector<bool>& vis, int& count,
                    vector<vector<int>>& arr) {
        int n = count;
        if (arr[node].size() != n - 1) {
            return false;
        }
        for (int e : arr[node]) {
            if (arr[e].size() != n - 1) {
                return false;
            }
        }
        return true;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> arr(n, vector<int>(0));
        vector<bool> vis(n, false);
        for (auto i : edges) {
            arr[i[0]].push_back(i[1]);
            arr[i[1]].push_back(i[0]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int count = 0;
                dfs(i, vis, count, arr);
                if (isComplete(i, vis, count, arr)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};