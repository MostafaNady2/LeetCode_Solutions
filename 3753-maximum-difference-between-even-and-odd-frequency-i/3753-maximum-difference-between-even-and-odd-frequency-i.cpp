class Solution {
public:
    int maxDifference(string s)
{
	int n = s.length();
	int a[26];
	for (char c : s)
	{
		a[c - 'a']++;
	}
	int mxOdd = 0, mxEven = 0,mnOdd=n,mnEven=n;
	for (int p : a)
	{
		if (p != 0)
		{
			if (p & 1)
			{
				mxOdd = max(mxOdd, p);
				mnOdd = min(mnOdd, p);
			}
			else
			{
				mxEven = max(mxEven, p);
				mnEven = min(mnEven, p);
			}
		}
	}
	return max(mxOdd - mxEven, mxOdd - mnEven);
}
};