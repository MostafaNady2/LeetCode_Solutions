class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = 0;
        int full = numBottles;
        int empty = 0;
        int ch = numExchange;
        while (full > 0 || empty >= ch) {
            if (ch <= empty) {
                full++;
                empty -= ch;
                ch++;
            } else {
                if (full > 0) {
                    ans += full;
                    empty += full;
                    full = 0;
                }
            }
        }
        return ans;
    }
};