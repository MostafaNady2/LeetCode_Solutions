class Solution {
public:
vector<string> getLongestSubsequence(vector<string> &words,
									 vector<int> &groups)
{
	int n = words.size();
	vector<int> ans;
	int last;
	for (int i = 0; i < n; i++)
	{
		if(ans.empty()){
			last = groups[i];
			ans.push_back(i);
		}else{
			if(last != groups[i]){
				last = groups[i];
				ans.push_back(i);
			}
		}
	}
	vector<string> res(ans.size());
	for (int i = 0; i < ans.size(); i++)
	{
		res[i] = words[ans[i]];
	}
	return res;
}
};