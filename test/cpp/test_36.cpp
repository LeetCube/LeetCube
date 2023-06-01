#include "../../src/cpp/code_36.cpp"
#include "cpp_deps/boilerplate.hpp"

vector<vector<char>> get_board(const json& field) {
    vector<vector<char>> board;
    for (const auto& row : field.get<std::vector<std::vector<std::string>>>()) {
        std::vector<char> transformed_row;
        transformed_row.reserve(row.size());

        for (const auto& item : row) transformed_row.emplace_back(item[0]);

        board.push_back(transformed_row);
    }

    return board;
}

void test(Solution& sol, const json& input, const json& output) {
    vector<vector<char>> board = get_board(input["board"]);
    bool expected = output.get<bool>();
    bool res = sol.isValidSudoku(board);
    CHECK_EQ(res, expected);
}

TEST_CASE("") {
    TEST("test/test_json/test_36.json");
}