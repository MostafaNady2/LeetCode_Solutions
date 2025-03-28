class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size();
        int m = grid[0].size();
        bitset<1000000> vis;
        vector<int> ans(queries.size());
        vector<pair<int, int>> q;
        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, greater<>>
            pq;
        pq.push({grid[0][0], {0, 0}});
        vis[0 * m + 0] = 1;
        sort(q.begin(), q.end());
        int cnt = 0;
        int idx[4] = {0, 1, 0, -1};
        int idy[4] = {1, 0, -1, 0};
        for (int i = 0; i < q.size(); i++) {
            int value = q[i].first;
            int index = q[i].second;
            while (!pq.empty() && pq.top().first < value) {
                int row = pq.top().second.first;
                int col = pq.top().second.second;
                cnt++;
                pq.pop();
                for (int j = 0; j < 4; j++) {
                    int nrow = row + idx[j];
                    int ncol = col + idy[j];
                    if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                        !vis[nrow * m + ncol]) {
                        vis[nrow * m + ncol] = 1;
                        pq.push({grid[nrow][ncol], {nrow, ncol}});
                    }
                }
            }
            ans[index] = cnt;
        }
        return ans;
    }
};