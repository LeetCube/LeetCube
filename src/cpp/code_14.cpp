// 14. Longest Common Prefix (Easy)

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    /**
        Write a function to find the longest common prefix string amongst an array of strings.

        If there is no common prefix, return an empty string "".

        @pre 1 <= strs.length <= 200
        @pre 0 <= strs[i].length <= 200
        @pre strs[i] consists of only lowercase English letters.
    */
    string longestCommonPrefix(vector<string>& strs) {
        string common = strs[0];

        for (size_t i = 1; i < strs.size(); i++) {
            if (common.length() <= 0) break;
            string temp = "";
            for (size_t j = 0; j < common.length(); j++) {
                if (strs[i][j] == common[j])
                    temp += common[j];
                else
                    break;
            }
            common = temp;
        }
        return common;
    }
};
