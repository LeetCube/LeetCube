#include <set>
#include <vector>

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

    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        for (const auto& row : board) {
            std::set<char> seen{};
            for (auto elem : row) {
                if (!is_grid_sequence_valid(seen, elem)) {
                    return false;
                }
            }
        }
        for (int col = 0; col < 9; col++) {
            std::set<char> seen{};
            for (int row = 0; row < 9; row++) {
                if (!is_grid_sequence_valid(seen, board[row][col])) {
                    return false;
                }
            }
        }
        for (int subbox = 0; subbox < 9; subbox++) {
            const auto box_top_left_x = 3*(subbox % 3);
            const auto box_top_left_y = 3*(subbox / 3);
            std::set<char> seen{};
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