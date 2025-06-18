class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i += 3) {
            temp.push_back(nums[i]);
            temp.push_back(nums[i + 1]);
            temp.push_back(nums[i + 2]);
            if (temp[2] - temp[0] > k) {
                return vector<vector<int>>();
            } else {
                ans.push_back(temp);
                temp.clear();
            }
        }
        return ans;
    }
};