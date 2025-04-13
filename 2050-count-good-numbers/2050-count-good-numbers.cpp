#define mod 1000000007
class Solution {
public:
    // primes 2 5 7 9
    // even 0 2 4 6 8
    // 4 --> e even  + 2 odd --> 5^numOfEven * 3^numOfOdd

    long long power(long long x, long long y, long long p) {
        x = x % p;
        y = y % (p - 1);
        if (y == 1 || x == 1) {
            return x;
        }
        if(y == 0){
            return 1;
        }
        long long h = power(x, y / 2, p);
        if (y % 2 == 0) {
            return (h * h) % p;
        } else {
            return (h * h * x) % p;
        }
        return 0;
    }
    int countGoodNumbers(long long n) {
        long odd = n / 2;
        long even = n - odd;
        long res = (power(5, even, mod) * power(4, odd, mod))%mod;
        return int(res);
    }
};