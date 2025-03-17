class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        bool ans;
        int i=1,n=nums.size();
        while(i < n){
            if(nums[i]!=nums[i-1]){
                return false;
            }
            i+=2;
        }
        return true;
    }
};