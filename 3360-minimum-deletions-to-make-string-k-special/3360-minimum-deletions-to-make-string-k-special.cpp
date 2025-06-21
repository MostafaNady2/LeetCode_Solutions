class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> mp;
        for (char c : word) {
            mp[c]++;
        }
        int ans = word.length();
        for (auto p : mp) {
            int cnt = 0;
            for (auto q : mp) {
                if (p.second > q.second) {
                    cnt += q.second;
                }
                else if (abs(p.second - q.second) > k) {
                    cnt += abs(p.second - q.second) - k;
                }
            }
            ans = min(ans, cnt);
        }
        return ans;
    }
};