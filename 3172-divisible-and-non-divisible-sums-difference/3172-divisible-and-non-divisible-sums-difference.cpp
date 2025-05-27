class Solution {
public:
    int differenceOfSums(int n, int m) {
        int cntm=n/m;
        long long sum2=1LL*m*(cntm*(cntm+1)/2);
        long long sum1=1LL*n*(n+1)/2;
        return int(sum1-2*sum2);
    }
};