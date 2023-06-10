#include <string>
#include <vector>

using namespace std;

// asdf
class Solution {
public:
    /**
        Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

        An input string is valid if:
            - Open brackets must be closed by the same type of brackets.
            - Open brackets must be closed in the correct order.
            - Every close bracket has a corresponding open bracket of the same type.

        @pre 1 <= s.length <= 10^4
        @pre s consists of parentheses only '()[]{}'.
    */
    bool isValid(string s) {
        vector<char> stack;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') stack.push_back(c);
            else {
                switch (c) {
                    case ')':
                        if (stack.empty() || stack.back() != '(') return false;
                        else stack.pop_back();
                        break;
                    case ']':
                        if (stack.empty() || stack.back() != '[') return false;
                        else stack.pop_back();
                        break;
                    case '}':
                        if (stack.empty() || stack.back() != '{') return false;
                        else stack.pop_back();
                        break;
                }
            }
        }

        return stack.empty();
    }
};