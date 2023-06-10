#include <vector>

using namespace std;

// asdf
class Solution {
public:
    /**
        An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

        Given an integer n, return the nth ugly number.

        @pre 1 <= n <= 1690
    */
    int nthUglyNumber(int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;

        int two = 0, three = 0, five = 0;

        for (int i = 1; i < n; ++i) {
            dp[i] = min(min(dp[two] * 2, dp[three] * 3), dp[five] * 5);

            if (dp[i] / dp[two] == 2) ++two;
            if (dp[i] / dp[three] == 3) ++three;
            if (dp[i] / dp[five] == 5) ++five;
        }

        return dp[n - 1];
    }
};