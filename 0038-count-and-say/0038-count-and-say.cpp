class Solution {
public:
    string countAndSay(int n) {
        string res = "1", t = "";
        char c;
        int i, cnt = 0;
        n--;
        while (n--) {
            c = res[0];
            i = 0;
            while (i < res.length()) {
                cnt = 0;
                while (i < res.length() && res[i] == c) {
                    cnt++;
                    i++;
                }
                t += to_string(cnt) + c;
                c = res[i];
            }
            res = t;
            t = "";
        }
        return res;
    }
};