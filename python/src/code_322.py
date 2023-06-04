from typing import List


class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        memo = {}

        def dp(num):
            if num in memo:
                return memo[num]
            if num < 0:
                return float("inf")
            if num == 0:
                return 0

            res = float("inf")
            for coin in coins:
                res = min(res, 1 + dp(num - coin))

            memo[num] = res
            return res

        res = dp(amount)
        return res if res != float("inf") else -1
