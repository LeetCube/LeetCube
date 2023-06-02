// 7. Reverse Integer (Medium)

#include <limits>

using namespace std;

class Solution {
public:
    /**
        Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.

        Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

        @pre -2^31 <= x <= 2^31 - 1
    */
    int reverse(int x) {
        int res = 0;

        while (x) {
            int last = x % 10;
            x /= 10;

            if (res > numeric_limits<int>::max() / 10 || res < numeric_limits<int>::min() / 10 || (res == numeric_limits<int>::max() / 10 && last > numeric_limits<int>::max() % 10) || (res == numeric_limits<int>::min() / 10 && last < numeric_limits<int>::min() % 10)) return 0;

            res = res * 10 + last;
        }

        return res;
    }
};