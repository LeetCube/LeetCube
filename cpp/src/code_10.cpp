// 10. Regular Expression Matching (Hard)

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    /**
        Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

        - '.' Matches any single character.​​​​
        - '*' Matches zero or more of the preceding element.

        The matching should cover the entire input string (not partial).

        @pre 1 <= s.length <= 20
        @pre 1 <= p.length <= 20
        @pre s contains only lowercase English letters.
        @pre p contains only lowercase English letters, '.', and '*'.
        @pre It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
    */
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.length() + 1, vector<bool>(p.length() + 1, false));
        dp[0][0] = true;

        for (size_t i = 0; i <= s.length(); ++i) {
            for (size_t j = 1; j <= p.length(); ++j) {
                if (p[j - 1] != '*') dp[i][j] = i && dp[i - 1][j - 1] && (p[j - 1] == s[i - 1] || p[j - 1] == '.');
                else dp[i][j] = dp[i][j - 2] || (i && dp[i - 1][j] && (p[j - 2] == s[i - 1] || p[j - 2] == '.'));
            }
        }

        return dp[s.length()][p.length()];
    }
};