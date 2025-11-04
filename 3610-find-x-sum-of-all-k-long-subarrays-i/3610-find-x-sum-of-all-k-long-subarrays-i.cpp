class Solution {
public:
    struct comp {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second < b.second;
        }
    };
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int xx = x, kk = k;
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp>
            pq; // {num,freq}
        int a[51];
        fill(a, a + 51, 0);
        int i = 1, n = nums.size();
        vector<int> ans;
        for (int j = 0; j < k && j < n; j++) {
            a[nums[j]]++;
        }
        for (int j = 1; j <= 50; j++) {
            if (a[j] > 0) {
                pq.push({j, a[j]});
            }
        }
        long long sum = 0;
        while (!pq.empty() && xx--) {
            sum += pq.top().first * pq.top().second;
            pq.pop();
        }
        ans.push_back(sum);
        sum = 0;

        while (i + k - 1 < n) {
            a[nums[i - 1]]--;
            a[nums[i + k - 1]]++;
            // refresh pq
            while (!pq.empty()) {
                pq.pop();
            }
            for (int j = 1; j <= 50; j++) {
                if (a[j] > 0) {
                    pq.push({j, a[j]});
                }
            }
            kk = k, xx = x;
            // get sum
            while (!pq.empty() && xx--) {
                sum += pq.top().first * pq.top().second;
                pq.pop();
            }
            ans.push_back(sum);
            sum = 0;
            i++;
        }
        return ans;
    }
};