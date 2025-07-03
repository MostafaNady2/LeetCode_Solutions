class Solution {
public:
    char run(string s, int k) {
        if (s.length() >= k) {
            return s[k-1];
        }
        int l = s.length(), i = 0;
        int c;
        while (i < l) {
            c = s[i];
            c++;
            s += (char)c;
            i++;
        }
        return run(s, k);
    }
    char kthCharacter(int k) { return run("a", k); }
};