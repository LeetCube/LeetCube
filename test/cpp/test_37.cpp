#include "../../src/cpp/code_37.cpp"
#include "cpp_deps/boilerplate.h"

Board get_board(const json& field) {
    Board board;
    for (const auto& row : field.get<std::vector<std::vector<std::string>>>()) {
        std::vector<char> transformed_row;

        for (const auto& item : row) transformed_row.push_back(item[0]);

        board.push_back(transformed_row);
    }

    return board;
}

void test(Solution& sol, const json& input, const json& output) {
    Board board = get_board(input["board"]);
    Board expected = get_board(output);
    sol.solveSudoku(board);
    CHECK_EQ(board, expected);
}

TEST_CASE("") {
    TEST("test/test_json/test_37.json");
}