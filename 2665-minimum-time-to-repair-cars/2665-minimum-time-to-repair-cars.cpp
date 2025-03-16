class Solution {
public:
    bool can(long long t, int cars, vector<int>& ranks) {
        int cnt = 0;
        for (int ele : ranks) {
            cnt += (long long)sqrt((double)t / ele);
            if (cnt >= cars) {
                return true;
            }
        }
        return cnt >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long i = 1;
        long long j =
            1LL * (*max_element(ranks.begin(), ranks.end())) * cars * cars;
        long long ans = j;

        while (i <= j) {
            long long mid = (i + j) / 2;
            if (can(mid, cars, ranks)) {
                ans = mid;
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return ans;
    }
};