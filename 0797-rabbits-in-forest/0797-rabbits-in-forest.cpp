class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int, int> m;
        int n = answers.size();
        for (int i = 0; i < n; i++) {
            m[answers[i]]++;
        }
        int ans = 0;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->first == 0) {
                ans += it->second;
            } else {
                if (it->second >= it->first) {
                    ans += ((it->second + it->first ) / (it->first+1)) *
                           (it->first + 1);
                } else {
                    ans += it->first + 1;
                }
            }
        }
        return ans;
    }
};