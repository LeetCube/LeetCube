from typing import List


class Solution:
    lookup = {
        "2": "abc",
        "3": "def",
        "4": "ghi",
        "5": "jkl",
        "6": "mno",
        "7": "pqrs",
        "8": "tuv",
        "9": "wxyz",
    }

    def letterCombinations(self, digits: str) -> List[str]:
        if len(digits) == 0:
            return []

        res = []
        stack = []

        def backtrack(index):
            if index == len(digits):
                res.append("".join(stack))
                return

            for c in self.lookup[digits[index]]:
                stack.append(c)
                backtrack(index + 1)
                stack.pop()

        backtrack(0)
        return res
