from typing import List
import math


class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        memo = {}

        def dp(num: int) -> int:
            if num in memo:
                return memo[num]
            if num < 0:
                return math.inf
            if num == 0:
                return 0

            res = math.inf
            for coin in coins:
                res = min(res, 1 + dp(num - coin))

            memo[num] = res
            return res

        res = dp(amount)
        return res if res != math.inf else -1
