class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        bool rev = true;
        vector<int> t;
        for (int i = 0; i < mat[0].size(); i++) {
            for (int col = i, row = 0; col >= 0 && row < mat.size();
                 col--, row++) {
                t.push_back(mat[row][col]);
            }
            if (rev) {
                while (!t.empty()) {
                    ans.push_back(t.back());
                    t.pop_back();
                }
            } else {
                for (auto u : t) {
                    ans.push_back(u);
                }
                t.clear();
            }
            rev = !rev;
        }
        for (int i = 1; i < mat.size(); i++) {
            for (int row = i, col = mat[0].size() - 1;
                 row < mat.size() && col >= 0; col--, row++) {
                t.push_back(mat[row][col]);
            }
            if (rev) {
                while (!t.empty()) {
                    ans.push_back(t.back());
                    t.pop_back();
                }
            } else {
                for (auto u : t) {
                    ans.push_back(u);
                }
                t.clear();
            }
            rev = !rev;
        }
        return ans;
    }
};