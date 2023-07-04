from typing import List


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]

        single = 0

        for i in range(31, -1, -1):
            bitCount = 0
            bitMask = 2**i

            for n in nums:
                bitCount += (n & bitMask) >> i

            bitCount %= 3

            if bitCount == 1:
                addVal = bitCount << i

                if i == 31:
                    single -= addVal
                else:
                    single += addVal

        return single
