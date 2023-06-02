from collections import defaultdict
from typing import List


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = defaultdict(int)
        for n in nums:
            freq[n] += 1

        sorted_items = sorted(freq.items(), key=lambda item: item[1], reverse=True)
        first_k = sorted_items[:k]
        return [i[0] for i in first_k]
