class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        if k == 0:
            return nums

        averages = [-1] * len(nums)

        if k > 0:
            sum = 0

            for i in range(len(nums)):
                if i - k < 0 or i + k >= len(nums):
                    continue
                
                if i - k == 0:
                    for j in range(i - k, i + k + 1):
                        sum += nums[j]
                else:
                    sum -= nums[i - k - 1]
                    sum += nums[i + k]
                
                averages[i] = int(sum / (2 * k + 1))

        return averages
