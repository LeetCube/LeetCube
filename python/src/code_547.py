from typing import List


class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        adj = {}
        N = len(isConnected)
        cities = [0] * N

        for i in range(N):
            if i not in adj:
                adj[i] = set()
            for j in range(N):
                if i == j:
                    continue

                if isConnected[i][j]:
                    if j not in adj:
                        adj[j] = set()
                    adj[i].add(j)
                    adj[j].add(i)

        def dfs(node, visited, province):
            if node in visited:
                return
            visited.add(node)
            for n in adj[node]:
                cities[n] = province
                dfs(n, visited, province)

        for i in range(N):
            if cities[i] == 0:
                cities[i] = i + 1
                dfs(i, set(), i + 1)

        return len(set(cities))
