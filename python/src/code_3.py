class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s:
            return 0

        exist = {}

        start = 0
        resLen = 1
        for end in range(len(s)):
            exist[s[end]] = exist.get(s[end], 0) + 1
            
            while end - start + 1 != len(exist):
                exist[s[start]] -= 1
                if exist[s[start]] == 0:
                    del exist[s[start]]
                start += 1

            resLen = max(resLen, end - start + 1)
        return resLen
