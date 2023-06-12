from typing import List


class Solution:
    def ways(self, pizza: List[str], k: int) -> int:
        rows, cols = len(pizza), len(pizza[0])
        prefixGrid = [[0] * (cols + 1) for _ in range(rows + 1)]

        for r in range(rows - 1, -1, -1):
            for c in range(cols - 1, -1, -1):
                prefixGrid[r][c] = (
                    int(pizza[r][c] == "A")
                    + prefixGrid[r + 1][c]
                    + prefixGrid[r][c + 1]
                    - prefixGrid[r + 1][c + 1]
                )

        def count(x1: int, y1: int, x2: int, y2: int):
            return (
                prefixGrid[x1][y1]
                + prefixGrid[x2][y2]
                - prefixGrid[x1][y2]
                - prefixGrid[x2][y1]
            )

        memo = {}

        def dp(x: int, y: int, k: int) -> int:
            if (x, y, k) in memo:
                return memo[(x, y, k)]
            if k == 0:
                return 0
            if k == 1 and count(x, y, rows, cols) >= 1:
                return 1

            res, mod = 0, 10**9 + 7

            for r in range(x + 1, rows):
                if count(x, y, r, cols) >= 1:
                    res = (res + dp(r, y, k - 1)) % mod

            for c in range(y + 1, cols):
                if count(x, y, rows, c) >= 1:
                    res = (res + dp(x, c, k - 1)) % mod

            memo[(x, y, k)] = res
            return res

        return dp(0, 0, k)
