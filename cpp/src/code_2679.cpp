#include <vector>

using namespace std;

class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        const int num_cols{static_cast<int>(nums[0].size())};

        int total_sum{0};

        while (true) {
            int largest_removed_num{0};

            for (auto& row : nums) {
                int largest_num_row{0};
                int largest_num_row_idx{-1};
                for (int col = 0; col < num_cols; col++) {
                    if (row[col] > largest_num_row) {
                        largest_num_row = row[col];
                        largest_num_row_idx = col;
                    }
                }
                if (largest_num_row_idx >= 0) { row[largest_num_row_idx] = 0; }
                largest_removed_num = std::max(largest_num_row, largest_removed_num);
            }
            if (largest_removed_num == 0) { break; }
            total_sum += largest_removed_num;
        }

        return total_sum;
    }
};