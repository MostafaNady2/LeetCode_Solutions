class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        vector<int> pairs;
        sort(potions.begin(), potions.end());
        int n = potions.size();
        for (auto v : spells) {
            int ans = -1;
            int i = 0, j = n - 1;
            while (i <= j) {
                int mid = (i + j) / 2;
                if ((1LL * v * potions[mid]) < success) {
                    i = mid + 1;
                } else {
                    ans = mid;
                    j = mid - 1;
                }
            }
            pairs.push_back((ans == -1) ? 0 : n - ans);
        }
        return pairs;
    }
};