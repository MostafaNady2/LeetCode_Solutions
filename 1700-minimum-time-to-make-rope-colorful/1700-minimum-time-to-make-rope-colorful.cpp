class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i = 0, j = 0, n = colors.length(), ans = 0, sum = 0, mx = 0;
        while (i < n) {
            j = i, mx = 0, sum = 0;
            while (j < n && colors[j] == colors[i]) {
                sum += neededTime[j];
                mx = max(mx, neededTime[j]);
                j++;
            }
            ans += (sum - mx);
            i = j;
        }
        return ans;
    }
};