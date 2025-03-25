class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int, int>> vertical, horizontal;
        for (auto it : rectangles) {
            vertical.push_back({it[1], it[3]});
            horizontal.push_back({it[0], it[2]});
        }
        sort(vertical.begin(), vertical.end());
        int cuts = 0;
        int m = vertical.size();
        int last = vertical[0].second;
        for (int i = 1; i < m; i++) {
            if (vertical[i].first >= last) {
                cuts++;
            }
            last = max(last, vertical[i].second);
            if (cuts == 2) {
                return true;
            }
        }
        cuts = 0;
        sort(horizontal.begin(), horizontal.end());
        m = horizontal.size();
        last = horizontal[0].second;
        for (int i = 1; i < m; i++) {
            if (horizontal[i].first >= last) {
                cuts++;
            }
            last = max(last, horizontal[i].second);
            if (cuts == 2) {
                return true;
            }
        }
        return false;
    }
};