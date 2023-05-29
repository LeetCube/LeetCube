#include "cpp_deps/boilerplate.h"
#include "../../src/cpp/code_36.cpp"

void test(Solution& sol, const json& input, const json& output) {
    std::vector<std::vector<char>> board{};
    for (const auto& row : input.get<std::vector<std::vector<std::string>>>()) {
        std::vector<char> transformed_row{};
        for (const auto& item : row) {
            transformed_row.push_back(item[0]);
        }
        board.push_back(transformed_row);
    }
    auto expected = output.get<bool>();
    auto res = sol.isValidSudoku(board);
    CHECK_EQ(res, expected);
}

TEST_CASE("") {
    TEST("test/test_json/test_36.json");
}