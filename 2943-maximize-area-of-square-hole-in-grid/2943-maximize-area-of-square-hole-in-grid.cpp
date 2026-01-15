class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
                               vector<int>& vBars) {
        m += 2;
        n += 2;
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int l = 1, w = 1;
        for (int i = 0; i < hBars.size(); i=i) {
            int j = i + 1;
            while (j < hBars.size() && hBars[j] - hBars[j - 1] == 1) {
                j++;
            }
            l = max(l, (j - i));
            i = j;
        }
        for (int i = 0; i < vBars.size(); i=i) {
            int j = i + 1;
            while (j < vBars.size() && vBars[j] - vBars[j - 1] == 1) {
                j++;
            }
            w = max(w, (j - i));
            i = j;
        }
        // cout<<l+1 <<' '<<w+1;
        return min(l + 1, w + 1) * min(l + 1, w + 1);
    }
};