class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> mp;
        for (auto x : dominoes) {
            mp[{min(x[0], x[1]), max(x[0], x[1])}]++;
        }
        int ans = 0;
        for (auto x : mp) {
            ans += x.second * (x.second - 1) / 2;
        }
        return ans;
    }
};