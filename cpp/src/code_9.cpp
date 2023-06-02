// 9. Palindrome Number (Easy)

class Solution {
public:
    /**
        Given an integer x, return true if x is a palindrome, and false otherwise.

        @pre -2^31 <= x <= 2^31 - 1
    */
    bool isPalindrome(int x) {
        if (x < 0 || (x && !(x % 10))) return false;

        int half = 0;

        while (x > half) {
            half = half * 10 + x % 10;
            x /= 10;
        }

        return x == half || x == half / 10;
    }
};