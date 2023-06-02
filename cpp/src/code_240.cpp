// 240. Search a 2D Matrix II (Medium)

#include <vector>

using namespace std;

class Solution {
public:
    /**
        Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

        - Integers in each row are sorted in ascending from left to right.
        - Integers in each column are sorted in ascending from top to bottom.

        @pre m == matrix.length
        @pre n == matrix[i].length
        @pre 1 <= m, n <= 300
        @pre -10^9 <= matrix[i][j] <= 10^9
        @pre All the integers in each row are sorted in ascending order.
        @pre All the integers in each column are sorted in ascending order.
        @pre -10^9 <= target <= 10^9
    */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = m - 1;

        while (i < n && j < m) {
            if (matrix[j][i] == target) return true;
            else if (j && matrix[j][i] > target) --j;
            else ++i;
        }
        return false;
    }
};
