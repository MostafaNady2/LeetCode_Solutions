// #include<bits/stdc++.h>
class Solution {
public:
    void radixSort(vector<int>& arr) {
        int mx = *max_element(arr.begin(), arr.end());
        int round = to_string(mx).length();
        vector<vector<int>> vec(10);
        long long ex = 1;
        while (round--) {
            for (int i = 0; i < arr.size(); i++) {
                vec[(arr[i] / ex) % 10].push_back(arr[i]);
            }
            int j = 0;
            for (int i = 0; i < 10; i++) {
                for (int u : vec[i]) {
                    arr[j++] = u;
                }
                vec[i].clear();
            }
            ex *= 10;
        }
    }
    int maximumGap(vector<int>& nums) {
        radixSort(nums);
        int ans=0;
        int n= nums.size();
        for(int i = 1 ; i < n ; i++){
            ans=max(ans,nums[i]-nums[i-1]);
        }
        return ans;
    }
};