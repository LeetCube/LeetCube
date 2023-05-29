#include <set>
#include <vector>

using Board = std::vector<std::vector<char>>;
class Solution {
public:
    bool is_grid_sequence_valid(std::set<char>& seen, char entry) {
        if (entry == '.') {
            return true;
        }
        if (seen.find(entry) == seen.end()) {
            seen.insert(entry);
            return true;
        }
        return false;
    }

    bool isValidSudoku(const Board& board, int modified_x, int modified_y) {
        std::set<char> seen{};
        for (auto elem : board[modified_x]) {
            if (!is_grid_sequence_valid(seen, elem)) {
                    return false;
                }
        }
        seen.clear();
        for (int row = 0; row < 9; row++) {
            if (!is_grid_sequence_valid(seen, board[row][modified_y])) {
                return false;
            }
        }
        seen.clear();

        const auto box_top_left_x = 3*(modified_x / 3);
        const auto box_top_left_y = 3*(modified_y / 3);
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                if (!is_grid_sequence_valid(
                        seen, 
                        board[box_top_left_x + x][box_top_left_y + y])) {
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(Board& board) {
        solve_search(board, 0);
    }

    bool solve_search(Board& board, int curr_cell_num) {
        if (curr_cell_num >= 81) {
            return true;
        }
        int curr_x = curr_cell_num / 9;
        int curr_y = curr_cell_num % 9;

        if (board[curr_x][curr_y] != '.') {
            return solve_search(board, curr_cell_num + 1);
        }

        for (int entry = 1; entry <= 9; entry++) {
            board[curr_x][curr_y] = '0' + entry; 
            if (!isValidSudoku(board, curr_x, curr_y)) {
                board[curr_x][curr_y] = '.';
                continue;
            }
            auto valid = solve_search(board, curr_cell_num + 1);
            if (!valid) {
                board[curr_x][curr_y] = '.';
            } else {
                return true;
            }
        }
        return false;
    }
};