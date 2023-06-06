#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    /**
        Given an integer num, return a string representing its hexadecimal representation. For negative integers, two’s complement method is used.

        All the letters in the answer string should be lowercase characters, and there should not be any leading zeros in the answer except for the zero itself.

        Note: You are not allowed to use any built-in library method to directly solve this problem.

        @pre -2^31 <= num <= 2^31 - 1
    */
    string toHex(int num) {
        if (!num) return "0";

        char hexits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        unsigned n = num;
        string res;

        while (n) {
            res += hexits[n & 0b1111];
            n >>= 4;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};