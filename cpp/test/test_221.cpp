#include "../src/code_221.cpp"
#include "cpp_deps/boilerplate.hpp"

vector<vector<char>> get_matrix(const json& field) {
    vector<vector<char>> matrix;

    for (const auto& row : field.get<std::vector<std::vector<std::string>>>()) {
        std::vector<char> transformed_row;

        for (const auto& item : row) transformed_row.push_back(item[0]);

        matrix.push_back(transformed_row);
    }

    return matrix;
}

void test(Solution& sol, const json& input, const json& output) {
    vector<vector<char>> matrix = get_matrix(input["matrix"]);
    int expected = output.get<int>();
    int result = sol.maximalSquare(matrix);
    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST(221);
}