from typing import List


class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        subArraySum = 0
        numElements = 0
        i = 0
        lowestLength = 100001

        for n in nums:
            subArraySum += n
            numElements += 1

            while subArraySum >= target:
                if numElements < lowestLength:
                    lowestLength = numElements

                subArraySum -= nums[i]
                numElements -= 1
                i += 1

        if lowestLength == 100001:
            return 0
        else:
            return lowestLength
