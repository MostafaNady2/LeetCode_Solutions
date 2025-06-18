class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        bool flag = false;
        for (int i = 0; i < n && !flag; i++) {
            temp.push_back(nums[i]);
            if (temp.size() % 3 == 0) {
                if (temp[2] - temp[0] > k) {
                    flag = true;
                    return vector<vector<int>>();
                }
                ans.push_back(temp);
                temp.clear();
            }
        }
        if (flag)
            return vector<vector<int>>();
        return ans;
    }
};