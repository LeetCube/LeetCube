// 934. Shortest Bridge (Medium)

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
    const pair<int, int> DIRS[4] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

public:
    /**
        You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

        An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

        You may change 0's to 1's to connect the two islands to form one island.

        Return the smallest number of 0's you must flip to connect the two islands.

        @pre n == grid.length == grid[i].length
        @pre 2 <= n <= 100
        @pre grid[i][j] is either 0 or 1.
        @pre There are exactly two islands in grid.
    */
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int, int>> stack;
        stack.reserve(n * n / 2);

        for (int i = 0; i < n * n; ++i) {
            if (grid[i / n][i % n] == 1) {
                stack.emplace_back(i % n, i / n);
                break;
            }
        }

        vector<pair<int, int>> curr_ring;
        curr_ring.reserve(4 * n);

        while (!stack.empty()) {
            pair<int, int> curr = stack.back();
            stack.pop_back();

            if (grid[curr.second][curr.first] != -1) {
                bool is_edge = false;
                grid[curr.second][curr.first] = -1;

                for (const auto& d : DIRS) {
                    pair<int, int> neighbour = {curr.first + d.first, curr.second + d.second};

                    if (0 <= neighbour.first && neighbour.first < n && 0 <= neighbour.second && neighbour.second < n && grid[neighbour.second][neighbour.first] != -1) {
                        if (grid[neighbour.second][neighbour.first] == 1) stack.push_back(neighbour);
                        else is_edge = true;
                    }
                }

                if (is_edge) curr_ring.push_back(curr);
            }
        }

        vector<pair<int, int>> next_ring;
        next_ring.reserve(curr_ring.size() * 4);

        for (int distance = 0;; ++distance) {
            for (const auto& curr : curr_ring) {
                for (const auto& d : DIRS) {
                    pair<int, int> neighbour = {curr.first + d.first, curr.second + d.second};

                    if (0 <= neighbour.first && neighbour.first < n && 0 <= neighbour.second && neighbour.second < n && grid[neighbour.second][neighbour.first] != -1) {
                        if (grid[neighbour.second][neighbour.first] == 1) return distance;
                        else {
                            grid[neighbour.second][neighbour.first] = -1;
                            next_ring.push_back(neighbour);
                        }
                    }
                }
            }

            curr_ring = next_ring;
            next_ring.clear();
            next_ring.reserve(curr_ring.size() * 4);
        }

        return -1;
    }
};