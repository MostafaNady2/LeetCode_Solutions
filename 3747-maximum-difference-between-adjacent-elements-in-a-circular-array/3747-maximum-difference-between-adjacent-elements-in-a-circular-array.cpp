class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int ans=0,n=nums.size();
        for(int i = 0 ; i < n; i++){
            ans=max(abs(nums[i] - nums[(i+1)%n]),ans);
        }
        return ans;
    }
};