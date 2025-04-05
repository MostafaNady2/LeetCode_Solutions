class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n= nums.size();
        int xor_all=0;
        int sub_xor=0;
        for(int i = 0 ; i < (1<<n);i++){
            for(int j = 0 ; j < n ; j++){
                if((i>>j)&1){
                    sub_xor ^= nums[j];
                }
            }
            xor_all += sub_xor;
            sub_xor=0;
        }
        return xor_all;
    }
};