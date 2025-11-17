class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        vector<int> idx;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                idx.push_back(i);
            }
        }

        n = idx.size();
        for (int i = 1; i < n; i++) {
            if (idx[i] - idx[i - 1]-1 < k) {
                return false;
            }
        }
        return true;
    }
};