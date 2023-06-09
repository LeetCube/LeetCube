#include <optional>
#include <variant>

#include "../src/code_677.cpp"
#include "cpp_deps/boilerplate.hpp"

using Param = vector<variant<string, int>>;
using Result = optional<int>;

class Solution {
public:
    MapSum* obj = nullptr;
};

vector<Param> get_params(const json& input) {
    vector<Param> res(input.size());

    for (size_t i = 0; i < input.size(); ++i) {
        for (const auto& v : input[i]) {
            if (v.is_string()) res[i].emplace_back(v.get<string>());
            else res[i].emplace_back(v.get<int>());
        }
    }

    return res;
}

vector<Result> get_results(const json& output) {
    vector<Result> res(output.size());

    for (size_t i = 0; i < output.size(); ++i) {
        if (!output[i].is_null()) res[i].emplace(output[i].get<int>());
    }

    return res;
}

void test(Solution& sol, const json& input, const json& output) {
    vector<string> ops = input["ops"].get<vector<string>>();
    vector<Param> params = get_params(input["params"]);
    vector<Result> expecteds = get_results(output);

    for (size_t i = 0; i < ops.size(); ++i) {
        string op = ops[i];
        Param param = params[i];
        Result expected = expecteds[i];

        if (op == "MapSum") {
            CHECK_EQ(param.size(), 0);
            sol.obj = new MapSum();
            CHECK_FALSE(expected.has_value());  // make sure test data isn't bugged
        } else if (op == "insert") {
            CHECK_EQ(param.size(), 2);
            sol.obj->insert(get<string>(param[0]), get<int>(param[1]));
            CHECK_FALSE(expected.has_value());  // make sure test data isn't bugged
        } else if (op == "sum") {
            CHECK_EQ(param.size(), 1);
            int result = sol.obj->sum(get<string>(param[0]));
            CHECK(expected.has_value());
            CHECK_EQ(result, expected.value());
        } else FAIL("invalid op");
    }

    delete sol.obj;
}

TEST_CASE("") {
    TEST(677)
}