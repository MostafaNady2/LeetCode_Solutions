class Solution {
public:
    void dfs(int node, vector<bool>& vis, vector<int>& comp,
             vector<vector<int>>& arr) {
        vis[node] = true;
        comp.push_back(node);
        for (auto i : arr[node]) {
            if (!vis[i]) {
                dfs(i, vis, comp, arr);
            }
        }
    }
    bool isComplete(int node, vector<bool>& vis, vector<int>& comp,
                    vector<vector<int>>& arr) {
        int n = comp.size();
        for (int e : comp) {
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
        for(int i = 0 ; i < n; i++) {
            if (!vis[i]) {
                vector<int> comp;
                dfs(i, vis, comp, arr);
                if (isComplete(i, vis, comp, arr)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};