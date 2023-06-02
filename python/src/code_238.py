from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        if n == 0 or n == 1:
            return nums

        left_product = [1] * n
        left_product[0] = nums[0]

        right_product = [1] * n
        right_product[n - 1] = nums[n - 1]

        for i in range(1, n):
            left_product[i] = left_product[i - 1] * nums[i]

        for i in range(n - 2, -1, -1):
            right_product[i] = right_product[i + 1] * nums[i]

        res = [1] * n
        for i in range(0, n):
            if i == 0:
                res[i] = right_product[1]
            elif i == n - 1:
                res[i] = left_product[n - 2]
            else:
                res[i] = left_product[i - 1] * right_product[i + 1]

        return res
