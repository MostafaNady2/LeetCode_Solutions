class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> f(501,0);
        int ans=-1;
        for(int num : arr){
            f[num]++;
        }
        for(int i =1;i <f.size();i++){
            if(i==f[i]){
                ans=max(ans,i);
            }
        }
        return ans;
    }
};