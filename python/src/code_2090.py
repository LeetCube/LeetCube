from typing import List


class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        if k == 0:
            return nums

        N = len(nums)
        averages = [-1] * N
        sum = 0

        for i in range(k, N - k):
            if i == k:
                for j in range(i + k + 1):
                    sum += nums[j]
            else:
                sum -= nums[i - k - 1]
                sum += nums[i + k]

            averages[i] = sum // (2 * k + 1)

        return averages
