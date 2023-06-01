from collections import defaultdict
from typing import List


def hash(chars: List[int]) -> int:
    res = 1
    for c in chars:
        res = 31 * res + c
    return res


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = defaultdict(list)
        for s in strs:
            freq = [0] * 26
            for c in s:
                freq[ord(c) - ord("a")] += 1

            anagrams[hash(freq)].append(s)

        res = []
        for k, v in anagrams.items():
            res.append(v)

        return res
