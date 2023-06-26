from typing import List


class Solution:
    def singleNumberXORSolution(self, nums: List[int]) -> int:
        result = 0
        for i in range(len(nums)):
            result ^= nums[i]
        return result

    def singleNumberFreqTableSolution(self, nums: List[int]) -> int:
        frequencyDict = {}
        for i in nums:
            if i not in frequencyDict:
                frequencyDict[i] = 1
            else:
                frequencyDict[i] += 1

        for i in frequencyDict:
            if frequencyDict[i] == 1:
                return i
