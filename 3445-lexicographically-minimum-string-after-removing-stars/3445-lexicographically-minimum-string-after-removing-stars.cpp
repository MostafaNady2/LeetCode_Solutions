class Solution {
public:
    struct Comp {
        bool operator()(const pair<char, int>& a, const pair<char, int>& b) {
            if (a.first != b.first)
                return a.first > b.first;
            return a.second < b.second;
        }
    };
    string clearStars(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, Comp> pq;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] != '*') {
                pq.push({s[i], i});
            }
            if (s[i] == '*') {
                if (!pq.empty()) {
                    s[pq.top().second] = '0';
                    pq.pop();
                }
                s[i] = '0';
            }
        }
        string ans;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                continue;
            }
            ans += s[i];
        }
        return ans;
    }
};