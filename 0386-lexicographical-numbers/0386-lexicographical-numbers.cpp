class Solution {
public:
    void dfs(int val, int n,vector<int> &v) {
        if (val <= n) {
            v.push_back(val);
            for (int i = 0; val * 10 + i <= n && i < 10; i++) {
                dfs(val * 10 + i, n,v);
            }
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for (int i = 1; i <= min(n, 9); i++) {
            dfs(i, n, ans);
        }
        return ans;
    }
};