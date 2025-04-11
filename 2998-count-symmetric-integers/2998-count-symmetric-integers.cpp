class Solution {
public:
    bool check(int num) {
        int l = to_string(num).length();
        if (l % 2 == 1) {
            return false;
        }
        int mid = l / 2;
        int sum1 = 0, sum2 = 0;
        while (mid--) {
            sum1 += num % 10;
            num /= 10;
        }
        while (num) {
            sum2 += num % 10;
            num /= 10;
        }
        return sum1 == sum2;
    }
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int i = low; i <= high; i++) {
            if (check(i)) {
                ans++;
            }
        }
        return ans;
    }
};