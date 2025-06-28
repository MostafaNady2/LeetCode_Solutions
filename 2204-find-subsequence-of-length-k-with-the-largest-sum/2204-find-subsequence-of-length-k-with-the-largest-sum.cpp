class Solution {
public:
    vector<int> maxSubsequence(vector<int> &nums, int k)
{
	int n=nums.size();
	vector<pair<int,int>> vp;
	for(int i =0;i < n ;i++){
		vp.emplace_back(nums[i],i);
	}
	sort(vp.rbegin(),vp.rend());
	sort(vp.begin(),vp.begin()+k,[](pair<int,int> a,pair<int,int> b){
		return a.second < b.second;
	});
	nums.clear();
	int id=0;
	while(!vp.empty() && k--){
		nums.push_back(vp[id].first);
		id++;
	}
	return nums;
}
};