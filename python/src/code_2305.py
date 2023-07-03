from typing import List
from math import inf


class Solution:
    def distributeCookies(self, cookies: List[int], k: int) -> int:
        N = len(cookies)
        distribution = [0] * k

        def dfs(i: int, count_empty: int) -> int:
            if i == N:
                return max(distribution)
            if N - i < count_empty:
                return inf

            answer = inf
            for j in range(k):
                count_empty -= int(distribution[j] == 0)
                distribution[j] += cookies[i]
                answer = min(answer, dfs(i + 1, count_empty))
                distribution[j] -= cookies[i]
                count_empty += int(distribution[j] == 0)

            return answer

        return dfs(0, k)
