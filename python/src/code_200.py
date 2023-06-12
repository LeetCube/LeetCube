from typing import List


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        count = 0
        rows, cols = len(grid), len(grid[0])

        def dfs(x: int, y: int):
            if x not in range(rows) or y not in range(cols) or grid[x][y] != "1":
                return

            grid[x][y] = "V"

            dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
            for dx, dy in dirs:
                dfs(x + dx, y + dy)

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == "1":
                    dfs(r, c)
                    count += 1
        return count
