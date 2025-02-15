class Solution {
public:
    bool can(int n, string s, int sum = 0) {
        if (s.empty()) {
            return sum == n;
        }

        for (int i = 1; i <= s.size(); i++) {
            int part = stoi(s.substr(0, i));
            if (can(n, s.substr(i), sum + part)) {
                return true;
            }
        }
        return false;
    }
    int punishmentNumber(int n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (can(i, to_string(i * i))) {
                sum += i * i;
            }
        }
        return sum;
    }
};