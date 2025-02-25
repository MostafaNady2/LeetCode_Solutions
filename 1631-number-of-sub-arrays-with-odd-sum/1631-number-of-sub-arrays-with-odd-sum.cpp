class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        long long mod = 1e9 + 7;
        vector<int> pre(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + arr[i - 1];
        }
        int odd = 0, even = 0;
        for (int i = 1; i <= n; i++) {
            if (pre[i] & 1) {
                odd++;
                ans++;
                ans += even;
            } else {
                even++;
                ans += odd;
            }

            ans %= mod;
        }
        return ans % mod;
    }
};