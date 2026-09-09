class Solution {
public:
    long long countCommas(long long n) {

        long long ans = 0;

        if (n >= 1000) {
            long long end = min(n, 999999LL);
            ans += (end - 1000 + 1);
        }

        if (n >= 1000000) {
            long long end = min(n, 999999999LL);
            ans += 2LL * (end - 1000000 + 1);
        }

        if (n >= 1000000000) {
            long long end = min(n, 999999999999LL);
            ans += 3LL * (end - 1000000000 + 1);
        }

        if (n >= 1000000000000LL) {
            long long end = min(n, 999999999999999LL);
            ans += 4LL * (end - 1000000000000LL + 1);
        }

        if (n >= 1000000000000000LL) {
            ans += 5LL * (n - 1000000000000000LL + 1);
        }

        return ans;
    }
};