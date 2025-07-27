class Solution {
public:
    int countHillValley(vector<int>& nums) {
	int ans = 0;
	int n = nums.size();
	for(int i = 1 ; i < n-1;i++){
		int j = i;
		while(j < n && nums[j]==nums[i]){
			j++;
		}
		if(j == n){
			break;
		}
		if((nums[i-1] > nums[i] && nums[j] > nums[i]) || (nums[i-1] < nums[i] && nums[j] < nums[i])){
			ans++;
		}
		i = j-1;
	}
	return ans;
}
};