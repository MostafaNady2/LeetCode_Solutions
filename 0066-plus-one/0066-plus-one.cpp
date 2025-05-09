class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int cnt = 0;
        while (!digits.empty() && digits.back() == 9) {
            digits.pop_back();
            cnt++;
        }
        if (digits.empty()) {
            digits.push_back(1);
        } else {

            digits[digits.size() - 1]++;
        }
        while (cnt--) {
            digits.push_back(0);
        }
        return digits;
    }
};