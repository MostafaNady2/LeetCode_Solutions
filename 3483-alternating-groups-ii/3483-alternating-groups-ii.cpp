class Solution {
public:
    int numberOfAlternatingGroups(vector<int> &colors, int k)
{
    int n = colors.size();
    int i = 0, j = 0;
    int ans = 0;
    int cnt = 0;
    while(cnt < k-1){
        colors.push_back(colors[cnt]);
        cnt++;
        n++;
    }
    while (i < n )
    {
        if (i + 1 < n && colors[i + 1] != colors[i])
        {
            if (i - j + 1 == k)
            {
                ans++;
                j++;
            }
            i++;
        }
        else
        {
            if (i - j + 1 == k)
            {
                ans++;
                j++;
            }
            i++;
            j = i;
        }
    }
    return ans;
}
};