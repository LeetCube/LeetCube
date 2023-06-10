#include <string>

using namespace std;

// asdf
class Solution {
public:
    /**
        The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

        P   A   H   N
        A P L S I I G
        Y   I   R

        And then read line by line: "PAHNAPLSIIGYIR"

        Write the code that will take a string and make this conversion given a number of rows:

        @pre 1 <= s.length <= 1000
        @pre s consists of English letters (lower-case and upper-case), ',' and '.'.
        @pre 1 <= numRows <= 1000
    */
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        string res;
        int num_in_pattern = 2 * (numRows - 1);

        for (int row = 0; row < numRows; ++row) {
            for (int i = row; i < (int)s.length(); i += num_in_pattern) {
                res.push_back(s[i]);
                int extra_index = i + num_in_pattern - 2 * row;

                if (row % (numRows - 1) && extra_index < (int)s.length()) res.push_back(s[extra_index]);
            }
        }

        return res;
    }
};