class Solution {
public:
    int numSub(string s) {
        int i = 0, n = s.length();
        long long cnt = 0;
        long long ans = 0;
        long long mod = 1000000007;
        while (i < n) {
            cnt = 0;
            bool f = false;
            while (i < n && s[i] == '1') {
                cnt++;
                i++;
                f = true;
            }
            if (f) {
                cnt = (((cnt + 1)%mod * cnt%mod)%mod) / 2;
                ans = (ans % mod + cnt % mod) % mod;
            } else {
                i++;
            }
        }
        return ans;
    }
};