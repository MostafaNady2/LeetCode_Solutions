class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int cnt01 = 0, cnt02 = 0;
        for (int i = 0; i < n; i++) {
            if (nums1[i] == 0)
                cnt01++;
        }
        for (int i = 0; i < m; i++) {
            if (nums2[i] == 0)
                cnt02++;
        }
        if (cnt01 && cnt02) {
            long long ac1 = accumulate(nums1.begin(), nums1.end(), 0LL);
            long long ac2 = accumulate(nums2.begin(), nums2.end(), 0LL);
            return max(ac1 + cnt01, ac2 + cnt02);
        } else {
            long long ac1 = accumulate(nums1.begin(), nums1.end(), 0LL);
            long long ac2 = accumulate(nums2.begin(), nums2.end(), 0LL);
            if (cnt01 == cnt02 && cnt01 == 0) {
                return ac1 == ac2 ? ac1 : -1;
            }
            if ((cnt01 && ac1 + cnt01 > ac2) || (cnt02 && ac2 + cnt02 > ac1)) {
                return -1;
            } else {
                if (cnt01) {
                    return max(ac1 + cnt01, ac2);
                } else {
                    return max(ac2 + cnt02, ac1);
                }
            }
        }
    }
};