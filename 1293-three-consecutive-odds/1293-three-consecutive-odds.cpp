class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n=arr.size();
        int idx=0;
        while(idx < n-2){
            if((arr[idx]&1) && (arr[idx+1]&1) && (arr[idx+2]&1)){
                return true;
            }
            idx++;
        }
        return false;
    }
};