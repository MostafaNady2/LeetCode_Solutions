class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0, ans = 0;
        for (int i : nums) {
            while (i) {
                i /= 10;
                cnt++;
            }
            ans += (!(cnt & 1));
            cnt = 0;
        }
        return ans;
    }
};