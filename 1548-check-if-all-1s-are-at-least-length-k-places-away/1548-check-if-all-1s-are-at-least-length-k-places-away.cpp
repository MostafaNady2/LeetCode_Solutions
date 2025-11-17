class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0,l=-1;
        while(i < n ){
            if(nums[i]==1){
                if(l > -1 && i-l-1 < k){
                    return false;
                }
                l=i;
            }
            i++;
        }
        return true;
    }
};