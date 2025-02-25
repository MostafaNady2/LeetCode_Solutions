class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        long long mod = 1e9 + 7, sum = 0;
        int odd = 0, even = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (sum & 1) {
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