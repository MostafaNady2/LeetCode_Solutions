class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int l = s.length();
        vector<string> res;
        for (int i = 0; i < l; i += k) {
            string t = s.substr(i, k);
            t += string(k - t.length(), fill);
            res.push_back(t);
        }
        return res;
    }
};