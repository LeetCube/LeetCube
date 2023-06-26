from typing import List


class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        mapping = {}
        result = []
        sortednums = sorted(nums)

        for i in range(len(sortednums)):
            if sortednums[i] not in mapping:
                mapping[sortednums[i]] = i

        for i in range(len(nums)):
            result.append(mapping[nums[i]])
        return result
