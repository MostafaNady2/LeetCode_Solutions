class Solution {
public:
    set<string> st;
    void g(int& n, string s, int idx) {
        if (idx == n && s.length() == n) {
            st.insert(s);
            return;
        }

        if (!s.empty() && s.back() != 'a') {
            s += 'a';
            g(n, s, idx + 1);
            s.pop_back();
        } else {
            if (s.empty()) {
                s += 'a';
                g(n, s, idx + 1);
                s.pop_back();
            }
        }

        if (!s.empty() && s.back() != 'b') {
            s += 'b';
            g(n, s, idx + 1);
            s.pop_back();
        } else {
            if (s.empty()) {
                s += 'b';
                g(n, s, idx + 1);
                s.pop_back();
            }
        }
        if (!s.empty() && s.back() != 'c') {
            s += 'c';
            g(n, s, idx + 1);
            s.pop_back();
        } else {
            if (s.empty()) {
                s += 'c';
                g(n, s, idx + 1);
                s.pop_back();
            }
        }
    }
    string getHappyString(int& n, int& k) {
        ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        g(n, "", 0);
        vector<string> vec(st.begin(), st.end());
        return (k > vec.size()) ? "" : vec[k - 1];
    }
};