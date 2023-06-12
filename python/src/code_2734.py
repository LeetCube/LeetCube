def op(c):
    if c == "a":
        return "z"
    else:
        return chr(ord(c) - 1)


class Solution:
    def smallestString(self, s: str) -> str:
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
