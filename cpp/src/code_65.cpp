#include <string>

using namespace std;

// asdf
class Solution {
    // order is {number, sign, dot, e}
    const int DFA[8][4] = {
        {1, 2, 3, 8},  // start 0
        {1, 8, 4, 5},  // number 1 VALID
        {1, 8, 3, 8},  // sign 2
        {4, 8, 8, 8},  // dot 3
        {4, 8, 8, 5},  // number dot 4 VALID
        {7, 6, 8, 8},  // e 5
        {7, 8, 8, 8},  // e sign 6
        {7, 8, 8, 8},  // e number 7 VALID
    };

public:
    /**
        A valid number can be split up into these components (in order):

        A decimal number or an integer.

        (Optional) An 'e' or 'E', followed by an integer.

        A decimal number can be split up into these components (in order):

        (Optional) A sign character (either '+' or '-').

        One of the following formats:
        One or more digits, followed by a dot '.'.

        One or more digits, followed by a dot '.', followed by one or more digits.

        A dot '.', followed by one or more digits.

        An integer can be split up into these components (in order):

        (Optional) A sign character (either '+' or '-').

        One or more digits.

        For example, all the following are valid numbers: ["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"], while the following are not valid numbers: ["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"].

        Given a string s, return true if s is a valid number.

        @pre 1 <= s.length <= 20
        @pre s consists of only English letters (both uppercase and lowercase), digits (0-9), plus '+', minus '-', or dot '.'.
    */
    bool isNumber(string s) {
        int state = 0;

        for (char c : s) {
            if (state == 8) return false;

            if ('0' <= c && c <= '9') state = DFA[state][0];
            else if (c == '+' || c == '-') state = DFA[state][1];
            else if (c == '.') state = DFA[state][2];
            else if (c == 'e' || c == 'E') state = DFA[state][3];
            else return false;
        }

        return state == 1 || state == 4 || state == 7;
    }
};