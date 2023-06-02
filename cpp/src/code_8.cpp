// 8. String to Integer (atoi) (Medium)

#include <limits>
#include <string>

using namespace std;

class Solution {
public:
    /**
        Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

        The algorithm for myAtoi(string s) is as follows:

        Read in and ignore any leading whitespace.

        Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.

        Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.

        Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).

        If the integer is out of the 32-bit signed integer range [-2^31, 2^31 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -2^31 should be clamped to -2^31, and integers greater than 2^31 - 1 should be clamped to 2^31 - 1.

        Return the integer as the final result.

        Note:
            - Only the space character ' ' is considered a whitespace character.
            - Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.

        @pre 0 <= s.length <= 200
        @pre s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.
    */
    int myAtoi(string s) {
        int res = 0, sign = 1;
        size_t idx = 0;

        while (s[idx] == ' ') ++idx;

        if (s[idx] == '-') {
            sign = -1;
            ++idx;
        } else if (s[idx] == '+') ++idx;

        while (s[idx] >= '0' && s[idx] <= '9') {
            if (res > numeric_limits<int>::max() / 10 || (res == numeric_limits<int>::max() / 10 && s[idx] > '7')) return sign == 1 ? numeric_limits<int>::max() : numeric_limits<int>::min();

            res = res * 10 + (s[idx++] - '0');
        }

        return res * sign;
    }
};