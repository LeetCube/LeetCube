// asdf
class Solution {
public:
    /**
        Write an algorithm to determine if a number n is happy.

        A happy number is a number defined by the following process:
            - Starting with any positive integer, replace the number by the sum of the squares of its digits.
            - Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
            - Those numbers for which this process ends in 1 are happy.

        Return true if n is a happy number, and false if not.

        @pre 1 <= n <= 2^31 - 1
    */
    bool isHappy(int n) {
        while (n != 1) {
            if (n == 4 || n == 16 || n == 37 || n == 58 || n == 89 || n == 145 || n == 42 || n == 20) return false;

            int next = 0;

            while (n) {
                next += (n % 10) * (n % 10);
                n /= 10;
            }

            n = next;
        }

        return true;
    }
};