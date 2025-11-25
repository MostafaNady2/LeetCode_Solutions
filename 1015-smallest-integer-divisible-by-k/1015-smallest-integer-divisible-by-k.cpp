class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k & 1) {
            int md = 0;
            for (int i = 1; i <= k; i++) {
                md = (md * 10 + 1) % k;
                if (md == 0) {
                    return i;
                }
            }
        }
        return -1;
    }
};