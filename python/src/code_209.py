from typing import List


class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        n = len(nums)
        subArraySum = 0
        left = 0
        lowestLength = n + 1

        for right, number in enumerate(nums):
            subArraySum += number

            while subArraySum >= target:
                lowestLength = min(lowestLength, right - left + 1)
                subArraySum -= nums[left]
                left += 1

        return 0 if lowestLength == n + 1 else lowestLength
