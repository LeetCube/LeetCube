from collections import deque


class Solution:
    def shortestBridge(self, grid: list[list[int]]) -> int:
        def neighbors(r: int, c: int):
            way4 = [(r - 1, c), (r + 1, c), (r, c - 1), (r, c + 1)]
            return [(nr, nc) for nr, nc in way4 if 0 <= nr < N and 0 <= nc < N]

        def dfs(r: int, c: int, visited: set[int]):
            visited.add((r, c))
            if grid[r][c]:
                grid[r][c] = 2
                island2.append((r, c))
                for nr, nc in neighbors(r, c):
                    if (nr, nc) not in visited and grid[nr][nc]:
                        dfs(nr, nc, visited)

        def bfs(q: deque[int]):
            # diff 1/2
            visited = set(q)
            dist = 0
            while q:
                water = deque([])
                for r, c in q:
                    for nr, nc in neighbors(r, c):
                        if (nr, nc) in visited:
                            continue
                        # diff 2/2
                        visited.add((nr, nc))
                        if grid[nr][nc] == 1:
                            return dist
                        elif grid[nr][nc] == 0:
                            water.append((nr, nc))
                q = water
                dist += 1

        def find_first():
            for i in range(N):
                for j in range(N):
                    if grid[i][j]:
                        return (i, j)

        N = len(grid)
        fr, fc = find_first()
        island2 = deque([])
        dfs(fr, fc, set())
        answer = bfs(island2)

        return answer

    def shortestBridgeTLE(self, grid: list[list[int]]) -> int:
        def neighbors(r: int, c: int):
            way4 = [(r - 1, c), (r + 1, c), (r, c - 1), (r, c + 1)]
            return [(nr, nc) for nr, nc in way4 if 0 <= nr < N and 0 <= nc < N]

        def dfs(r: int, c: int, visited: set[int]):
            visited.add((r, c))
            if grid[r][c]:
                grid[r][c] = 2
                island2.append((r, c))
                for nr, nc in neighbors(r, c):
                    if (nr, nc) not in visited and grid[nr][nc]:
                        dfs(nr, nc, visited)

        def bfs(q: deque[int]):
            # diff 1/2
            visited = set()
            dist = 0
            while q:
                water = deque([])
                for r, c in q:
                    # diff 2/2
                    visited.add((r, c))
                    for nr, nc in neighbors(r, c):
                        if (nr, nc) in visited:
                            continue
                        if grid[nr][nc] == 1:
                            return dist
                        elif grid[nr][nc] == 0:
                            water.append((nr, nc))
                q = water
                dist += 1

        def find_first():
            for i in range(N):
                for j in range(N):
                    if grid[i][j]:
                        return (i, j)

        N = len(grid)
        fr, fc = find_first()
        island2 = deque([])
        dfs(fr, fc, set())
        answer = bfs(island2)

        return answer
