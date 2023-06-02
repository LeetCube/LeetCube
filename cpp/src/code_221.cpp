// 221. Maximal Square (Medium)

#include <vector>

using namespace std;

class Solution {
public:
    /**
        Given an m x n binary matrix filled with 0's and 1's, find the largest
       square containing only 1's and return its area.

        @pre m == matrix.length
        @pre n == matrix[i].length
        @pre 1 <= m, n <= 300
        @pre matrix[i][j] is '0' or '1'.
    */
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> dp(n + 1, 0);
        int size = 0;
        int prev = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int temp = dp[j + 1];

                if (matrix[i][j] == '1') {
                    dp[j + 1] = min(min(dp[j], prev), dp[j + 1]) + 1;
                    size = max(size, dp[j + 1]);
                } else dp[j + 1] = 0;

                prev = temp;
            }
        }

        return size * size;
    }
};
