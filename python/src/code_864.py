from string import ascii_lowercase, ascii_uppercase
from collections import deque, defaultdict
from typing import List


class Solution:
    def shortestPathAllKeys(self, grid: List[str]) -> int:
        def neighbors(r: int, c: int):
            answers = [(r - 1, c), (r + 1, c), (r, c - 1), (r, c + 1)]
            answers = [(nr, nc) for (nr, nc) in answers if 0 <= nr < M and 0 <= nc < N]

            return answers

        M, N = len(grid), len(grid[0])
        keys_done = 0
        for i in range(M):
            for j in range(N):
                cell = grid[i][j]
                if cell == "@":
                    start_r, start_c = i, j
                elif cell in ascii_lowercase:
                    keys_done |= 1 << (ord(cell) - ord("a"))

        q = deque([(start_r, start_c, 0, 0)])
        visited = defaultdict(set)
        visited[0].add((start_r, start_c))

        while q:
            r, c, keys, dist = q.popleft()
            for nr, nc in neighbors(r, c):
                cell = grid[nr][nc]
                wall = cell == "#"
                locked = (cell in ascii_uppercase) and not (
                    keys & (1 << (ord(cell) - ord("A")))
                )
                if (nr, nc) in visited[keys] or wall or locked:
                    continue
                if cell in ascii_lowercase:
                    keys_new = keys | (1 << (ord(cell) - ord("a")))
                    if keys_new == keys_done:
                        return dist + 1

                    q.append((nr, nc, keys_new, dist + 1))
                    visited[keys_new].add((nr, nc))
                else:
                    q.append((nr, nc, keys, dist + 1))
                    visited[keys].add((nr, nc))

        return -1
