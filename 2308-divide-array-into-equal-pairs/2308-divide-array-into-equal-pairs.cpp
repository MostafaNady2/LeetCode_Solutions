class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        bool ans;
        int i=1,n=nums.size(),cnt=0;
        while(i < n){
            cnt=1;
            while(i < n && nums[i]==nums[i-1]){
                cnt++;
                i++;
            }
            if(cnt&1){
                return false;
            }
            i++;
        }
        return true;
    }
};