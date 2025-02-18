class Solution {
public:
    string s;
    bool valid(string& p, string& ans) {
        for (int i = 0; i < p.length(); i++) {
            if ((p[i] == 'I' && ans[i] - '0' >= ans[i + 1] - '0') ||
                (p[i] == 'D' && ans[i] - '0' <= ans[i + 1] - '0')) {
                return false;
            }
        }
        return true;
    }
    void g(string p, vector<bool>& v, string ans) {
        if (ans.length() == p.length() + 1 && valid(p, ans)) {
            s = min(s, ans);
            return;
        }
        for (int i = 1; i <= p.length() + 1; i++) {
            if (!v[i]) {
                if (!ans.empty() && ans.back() - '0' >= i &&
                    p[ans.length() - 1] == 'I') {
                    continue;
                }
                if (!ans.empty() && ans.back() - '0' <= i &&
                    p[ans.length() - 1] == 'D') {
                    continue;
                }
                v[i] = true;
                g(p, v, ans + to_string(i));
                v[i] = false;
            }
        }
    }

    string smallestNumber(string pattern) {
        s = "99999999";
        vector<bool> v(pattern.length() + 1, false);
        g(pattern, v, "");
        return s;
    }
};