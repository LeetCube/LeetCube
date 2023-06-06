class Solution {
public:
    /**
        Given an integer n, return the count of all numbers with unique digits, x, where 0 <= x < 10^n.

        @pre 0 <= n <= 8
    */
    int countNumbersWithUniqueDigits(int n) {
        int res = 1;

        for (int i = 9; i > 9 - n; --i) {
            int s = 9;

            for (int j = 9; j > i; --j) s *= j;

            res += s;
        }

        return res;
    }
};