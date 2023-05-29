#include "cpp_deps/boilerplate.h"
#include "../../src/cpp/code_37.cpp"

#include <iostream>

Board get_board(const json& field) {
    Board board{};
    for (const auto& row : field.get<std::vector<std::vector<std::string>>>()) {
        std::vector<char> transformed_row{};
        for (const auto& item : row) {
            transformed_row.push_back(item[0]);
        }
        board.push_back(transformed_row);
    }
    return board;
}

void test(Solution& sol, const json& input, const json& output) {
    Board input_board = get_board(input);

    Board expected_board = get_board(output);

    sol.solveSudoku(input_board);

    CHECK_EQ(input_board, expected_board);
}

TEST_CASE("") {
    TEST("test/test_json/test_37.json");
}