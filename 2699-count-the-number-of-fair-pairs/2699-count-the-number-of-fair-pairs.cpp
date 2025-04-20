class Solution {
public:
int bs(vector<int>& v, int l, int n, int val) {
    int ptr1 = l, ptr2 = n - 1, ans = l - 1;
    while (ptr1 <= ptr2) {
        int mid = ptr1 + (ptr2 - ptr1) / 2;
        if (v[mid] <= val) {
            ans = mid;
            ptr1 = mid + 1;
        } else {
            ptr2 = mid - 1;
        }
    }
    return ans;
}
long long countFairPairs(vector<int> &nums, int lower, int upper)
{
    long long ans = 0;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int l = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
        int r = bs(nums, i + 1, n, upper - nums[i]);
        if (r >= l)
        {
            ans += (long long)(r - l + 1);
        }
    }
    return ans;
}
};