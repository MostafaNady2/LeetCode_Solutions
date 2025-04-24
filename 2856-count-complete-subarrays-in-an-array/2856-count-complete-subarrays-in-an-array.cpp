class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int ans = 0, total = 0, n = nums.size();
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        total = mp.size();
        mp.clear();
        int j = 0;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
            if (mp.size() == total) {
                while (mp.size() == total) {
                    ans += (n - i);
                    mp[nums[j]]--;
                    if (mp[nums[j]] == 0) {
                        mp.erase(nums[j]);
                    }
                    j++;
                }
            }
        }
        return ans;
    }
};