class Solution {
public:
bool found = false;
set<string> st;
string g(int n, string ans)
{
    if (ans.length() == n && !found)
    {
        if (st.find(ans) == st.end())
        {
            found = true;
            return ans;
        }
        else
        {
            return "";
        }
    }
    if(found){
        return "";
    }
    return g(n, ans + '0') + g(n, ans + '1');
}
string findDifferentBinaryString(vector<string> &nums)
{
    int l = nums[0].length();
    for(string s : nums){
        st.insert(s);
    }
    return g(l, "");
}
};