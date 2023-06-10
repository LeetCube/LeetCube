#include <optional>

#include "../src/code_295.cpp"
#include "cpp_deps/boilerplate.hpp"

using Result = optional<double>;

// asdf
class Solution {
public:
    MedianFinder* obj = nullptr;
};

vector<Result> get_results(const json& output) {
    vector<Result> res(output.size());

    for (size_t i = 0; i < output.size(); ++i) {
        if (!output[i].is_null()) res[i].emplace(output[i].get<double>());
    }

    return res;
}

void test(Solution& sol, const json& input, const json& output) {
    vector<string> ops = input["ops"].get<vector<string>>();
    vector<vector<int>> params = input["params"].get<vector<vector<int>>>();
    vector<Result> expecteds = get_results(output);

    for (size_t i = 0; i < ops.size(); ++i) {
        string op = ops[i];
        vector<int> param = params[i];
        Result expected = expecteds[i];

        if (op == "MedianFinder") {
            CHECK_EQ(param.size(), 0);
            sol.obj = new MedianFinder();
            CHECK_FALSE(expected.has_value());  // make sure test data isn't bugged
        } else if (op == "addNum") {
            CHECK_EQ(param.size(), 1);
            sol.obj->addNum(param[0]);
            CHECK_FALSE(expected.has_value());  // make sure test data isn't bugged
        } else if (op == "findMedian") {
            CHECK_EQ(param.size(), 0);
            double result = sol.obj->findMedian();
            CHECK(expected.has_value());
            CHECK_EQ(result, expected.value());
        } else FAIL("invalid op");
    }

    delete sol.obj;
}

// asdf
TEST_CASE("") {
    TEST(295);
}