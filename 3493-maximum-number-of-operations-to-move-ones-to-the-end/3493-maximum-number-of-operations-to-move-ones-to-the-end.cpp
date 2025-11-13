class Solution {
public:
    int maxOperations(string s) {
        int cnt = 0;
        int ans = 0;
        int n = s.length();
        bool f = false;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (cnt && f) {
                    ans += cnt;
                    cnt++;
                } else {
                    cnt++;
                }
                f = false;
            } else {
                f = true;
            }
        }
        if (s[n - 1] == '0') {
            ans += cnt;
        }
        return ans;
    }
};