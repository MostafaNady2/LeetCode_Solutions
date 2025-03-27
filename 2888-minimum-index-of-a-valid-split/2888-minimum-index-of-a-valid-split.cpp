class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> idxs;
        for (int i = 0; i < n; i++) {
            idxs[nums[i]].push_back(i);
        }
        for (auto p : idxs) {
            int cnt = 0, currSize = 0;
            for (int i = 0; i < p.second.size() - 1; i++) {
                cnt++;
                currSize = (p.second[i] + 1) / 2;
                if (cnt > currSize &&
                    p.second.size() - cnt > (n - (p.second[i] + 1)) / 2) {
                    return p.second[i];
                }
            }
        }
        return -1;
    }
};