class Solution {
public:
    string ans = "";
    int i = 0;
    void g(int& n, string s, int idx, int k) {
        if (idx == n && s.length() == n) {
            i++;
            if (i == k) {
                ans = s;
            }
            return;
        }
        if (!ans.empty() || i == k) {
            return;
        }
        if (!s.empty() && s.back() != 'a') {
            s += 'a';
            g(n, s, idx + 1, k);
            s.pop_back();
        } else {
            if (s.empty()) {
                s += 'a';
                g(n, s, idx + 1, k);
                s.pop_back();
            }
        }

        if (!s.empty() && s.back() != 'b') {
            s += 'b';
            g(n, s, idx + 1, k);
            s.pop_back();
        } else {
            if (s.empty()) {
                s += 'b';
                g(n, s, idx + 1, k);
                s.pop_back();
            }
        }
        if (!s.empty() && s.back() != 'c') {
            s += 'c';
            g(n, s, idx + 1, k);
            s.pop_back();
        } else {
            if (s.empty()) {
                s += 'c';
                g(n, s, idx + 1, k);
                s.pop_back();
            }
        }
    }
    string getHappyString(int& n, int& k) {
        g(n, "", 0, k);
        this->i = 0;
        return ans;
    }
};