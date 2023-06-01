from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen = {}
        for i, n in enumerate(nums):
            if abs(target - n) in seen:
                return [seen[abs(target - n)], i]
            else:
                seen[n] = i
