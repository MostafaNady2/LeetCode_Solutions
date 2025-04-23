class Solution {
public:
    int sumOfDigits(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        map<int, int> mp;
        for (int i = 1; i <= n; i++) {
            mp[sumOfDigits(i)]++;
        }
        int mx = 0;
        for (auto it : mp) {
            mx = max(mx, it.second);
        }
        int ans = 0;
        for (auto it : mp) {
            if (it.second == mx) {
                ans++;
            }
        }
        return ans;
    }
};