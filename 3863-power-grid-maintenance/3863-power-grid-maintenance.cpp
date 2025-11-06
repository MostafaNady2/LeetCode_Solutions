class Solution {
public:
    vector<int> parent = vector<int>(100001);
    int getParent(int x) {
        if (parent[x] == x) {
            return x;
        }
        parent[x] = getParent(parent[x]);
        return parent[x];
    }
    void unionNodes(int a, int b) {
        a = getParent(a);
        b = getParent(b);
        if (a != b) {
            parent[b] = a;
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        for (int i = 1; i <= c; i++) {
            parent[i] = i;
        }
        vector<int> active(c + 1, 1);
        for (auto i : connections) {
            unionNodes(i[0], i[1]);
        }
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>>
            groups;
        for (int i = 1; i <= c; i++) {
            groups[getParent(i)].push(i);
        }
        vector<int> ans;
        for (auto q : queries) {
            int u = q[1];
            int root = getParent(u);
            if (q[0] == 1) {
                if (active[u]) {
                    ans.push_back(u);
                } else {
                    while (!groups[root].empty() &&
                           !active[groups[root].top()]) {
                        groups[root].pop();
                    }
                    if (!groups[root].empty()) {
                        ans.push_back(groups[root].top());
                    }else{
                        ans.push_back(-1);
                    }
                }
            } else {
                active[u] = 0;
            }
        }
        return ans;
    }
};