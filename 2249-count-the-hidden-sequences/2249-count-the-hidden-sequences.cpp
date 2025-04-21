class Solution {
public:
int numberOfArrays(vector<int>& differences, int lower, int upper) {
    int n = differences.size();
    vector<long long> v;
    v.push_back(0);
    for (int i = 0; i < n; i++) {
        v.push_back(v[i] + differences[i]);
    }
    int shift = lower - *min_element(v.begin(), v.end()); 
    int ans = upper - (*max_element(v.begin(), v.end()) + shift) + 1;
    return max(ans,0);
}
};