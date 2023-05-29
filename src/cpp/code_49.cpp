// 49. Group Anagrams (Medium)

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    /**
        Given an array of strings strs, group the anagrams together. You can return the answer in any order.

        An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

        @pre 1 <= strs.length <= 10^4
        @pre 0 <= strs[i].length <= 100
        @pre strs[i] consists of lowercase English letters.
    */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 1) return {strs};

        unordered_map<string, vector<string>> m;

        for (const string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            m[key].push_back(s);
        }

        vector<vector<string>> res;
        res.reserve(m.size());

        for (const auto& kv : m) res.emplace_back(kv.second);

        return res;
    }
};