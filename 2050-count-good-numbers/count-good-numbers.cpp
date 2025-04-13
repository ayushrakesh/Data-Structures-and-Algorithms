class Solution {
public:
    long long powXN(int x, long long n) {
        if (n == 0) {
            return 1;
        }

        long long l = 0;

        if (n % 2 == 0) {
            l = powXN(x, n / 2);
            return (l * l)%1000000007;
        } else {
            l = powXN(x, n - 1);
            return (l * x)%1000000007;
        }
    }

    int countGoodNumbers(long long n) {
        long long evenDigits = ceil(n / 2.0);
        long long oddDigits = floor(n / 2.0);

        // cout << evenDigits << " " << oddDigits << endl;
        return (powXN(5, evenDigits) * powXN(4, oddDigits))%1000000007;
    }
};