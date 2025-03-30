class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> first(26, -1), last(26, -1);

        for (int i = 0; i < s.size(); i++) {
            if (first[s[i] - 'a'] == -1) {
                first[s[i] - 'a'] = i;
            }
            last[s[i] - 'a'] = i;
        }

        vector<pair<int, int>> m;
        for (int i = 0; i < 26; i++) {
            if (first[i] != -1) {
                m.push_back({first[i], last[i]});
            }
        }

        sort(m.begin(), m.end());

        vector<int> ans;
        int ptr1 = m[0].first, ptr2 = m[0].second;

        for (int i = 1; i < m.size(); i++) {
            if (m[i].first <= ptr2) {
                ptr2 = max(ptr2, m[i].second);
            } else {
                ans.push_back(ptr2 - ptr1 + 1);
                ptr1 = m[i].first;
                ptr2 = m[i].second;
            }
        }
        ans.push_back(ptr2 - ptr1 + 1);

        return ans;
    }
};