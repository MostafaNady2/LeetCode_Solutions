#define all(v) v.begin(), v.end()

#define Unique(v) sort(all(v)), v.resize(unique(all(v)) - v.begin())

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> idx(n, 0);
        for (int i = 0; i < n; i++) {
            if (digits[i] % 2 == 0) {
                idx[i]++;
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (digits[i] == 0) {
                continue;
            }
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < idx.size(); k++) {
                    if (i == k || j == k || i == j || idx[k] == 0) {
                        continue;
                    }
                    ans.push_back(digits[i] * 100 + digits[j] * 10 + digits[k]);
                }
            }
        }
        Unique(ans);

        return ans;
    }
};