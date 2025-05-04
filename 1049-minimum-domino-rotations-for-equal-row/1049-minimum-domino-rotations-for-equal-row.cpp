class Solution {
public:
int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
{
    int n = tops.size();
    int ans = INT32_MAX;
    for (int i = 1; i <= 6; i++)
    {
        int cnt1 = 0, cnt2 = 0;
        bool f = false;
        for (int j = 0; j < n; j++)
        {
            if (tops[j] == i)
            {
                cnt1++;
            }
            if (bottoms[j] == i)
            {
                cnt2++;    // [3,5,1,2,3] , [3,6,3,3,4]
            }
            if (tops[j] != i && bottoms[j] != i)
            {
                break;
                f = true;
            }
        }
        if (!f && cnt1 + cnt2 >= n)
        {
            ans = min(ans, n - max(cnt1, cnt2));
        }
    }
    return ans == INT32_MAX ? -1 : ans;
}
};