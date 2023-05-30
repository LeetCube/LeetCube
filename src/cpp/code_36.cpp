// 36. Valid Sudoku (Medium)

#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    bool is_grid_sequence_valid(set<char>& seen, char entry) {
        if (entry == '.') {
            return true;
        }
        if (seen.find(entry) == seen.end()) {
            seen.insert(entry);
            return true;
        }
        return false;
    }

    /**
        Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

        Each row must contain the digits 1-9 without repetition.

        Each column must contain the digits 1-9 without repetition.

        Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

        Note:
            - A Sudoku board (partially filled) could be valid but is not necessarily solvable.
            - Only the filled cells need to be validated according to the mentioned rules.

        @pre board.length == 9
        @pre board[i].length == 9
        @pre board[i][j] is a digit 1-9 or '.'.
    */
    bool isValidSudoku(vector<vector<char>>& board) {
        for (const auto& row : board) {
            set<char> seen;
            for (auto elem : row) {
                if (!is_grid_sequence_valid(seen, elem)) {
                    return false;
                }
            }
        }
        for (int col = 0; col < 9; col++) {
            set<char> seen;
            for (int row = 0; row < 9; row++) {
                if (!is_grid_sequence_valid(seen, board[row][col])) {
                    return false;
                }
            }
        }
        for (int subbox = 0; subbox < 9; subbox++) {
            const auto box_top_left_x = 3 * (subbox % 3);
            const auto box_top_left_y = 3 * (subbox / 3);
            set<char> seen;
            for (int x = 0; x < 3; x++) {
                for (int y = 0; y < 3; y++) {
                    if (!is_grid_sequence_valid(
                            seen,
                            board[box_top_left_x + x][box_top_left_y + y])) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};