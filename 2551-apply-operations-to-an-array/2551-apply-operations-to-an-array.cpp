class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> v;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                if (nums[i] != 0) {
                    v.push_back(2*nums[i]);
                }
                nums[i + 1] = 0;
            } else {
                if (nums[i] != 0) {
                    v.push_back(nums[i]);
                }
            }
        }
        if(nums.back()!=0){
            v.push_back(nums.back());
        }
        // if(nums.size()==2 && nums[1] != nums[0]){
        //     if(nums[0]==0){
        //         swap(nums[0],nums[1]);
        //         return nums;
        //     }
        // }
        n = n - v.size();
        while (n--) {
            v.push_back(0);
        }
        
        return v;
    }
};