class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        long long last = 0, mn = last, mx = last;
        for (int i = 0; i < n; i++) {
            last += differences[i];
            mn = min(mn, last);
            mx = max(mx, last);
        }
        int shift = lower - mn;
        int ans = upper - (mx + shift) + 1;
        return max(ans, 0);
    }
};