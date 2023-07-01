# Requiem
class Solution:
    def smallestString(self, s: str) -> str:
        def op(c):
            if c == "a":
                return "z"
            else:
                return chr(ord(c) - 1)

        switched = False
        ans = []
        for i, c in enumerate(s):
            if c != "a":  # [0, i] all 'a'
                switched = True  # we will perform the switch
                ans += ["a"] * i
                for j in range(i, len(s)):
                    if s[j] == "a":
                        ans += [op(x) for x in s[i:j]]
                        ans += s[j:]
                        return "".join(ans)
                # only 1 a found, make rest prev letter
                ans += [op(x) for x in s[i:]]
                return "".join(ans)

        if not switched:
            return s[:-1] + "z"


# any
from string import ascii_lowercase


class Solution:
    def smallestString(self, s: str) -> str:
        def smallerChar(s: str):
            answer = ""
            for c in s:
                i = ord(c) - ord("a")
                answer += ascii_lowercase[i - 1]

            return answer

        N = len(s)
        i = 0
        while i < N and s[i] == "a":
            i += 1
        if i == N:
            return s[:-1] + "z"

        j = i
        while j < N and s[j] != "a":
            j += 1
        return s[:i] + smallerChar(s[i:j]) + s[j:]
