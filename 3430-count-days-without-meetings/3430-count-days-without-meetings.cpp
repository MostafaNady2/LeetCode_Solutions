class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(),
             [&](vector<int> a, vector<int> b) { return a[0] < b[0]; });
        int ans = meetings[0][0] - 1;
        int last = meetings[0][1];
        for (auto it : meetings) {
            if (it[0] > last) {
                ans += (it[0] - last - 1);
            }
            last = max(last, it[1]);
        }
        ans += (days - last);
        return ans;
    }
};