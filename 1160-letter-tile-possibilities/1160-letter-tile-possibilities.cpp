class Solution {
public:
    set<string> st;
    void g(string p, vector<bool> m, string s) {
        if (!s.empty() && st.find(s) == st.end()) {
            st.insert(s);
        }
        for (int i = 0; i < p.length(); i++) {
            if (m[i]) {
                continue;
            }
            m[i] = true;
            g(p, m, s + p[i]);
            m[i] = false;
        }
    }
    int numTilePossibilities(string tiles) {
        vector<bool> m(tiles.length(), false);
        g(tiles, m, "");
        return st.size();
    }
};