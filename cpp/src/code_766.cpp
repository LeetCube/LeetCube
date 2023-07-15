#include <vector>

using namespace std;

class Solution {
public:
    /**
        Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return false.

        A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.

        @pre m == matrix.length
        @pre n == matrix[i].length
        @pre 1 <= m, n <= 20
        @pre 0 <= matrix[i][j] <= 99
    */
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        for (int i = 0; i < m - 1; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                if (matrix[i][j] != matrix[i + 1][j + 1]) return false;
            }
        }

        return true;
    }
};