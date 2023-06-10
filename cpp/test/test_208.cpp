#include "../src/code_208.cpp"
#include "cpp_deps/boilerplate.hpp"

enum Result { TRUE = true, FALSE = false, NULLPTR = -1 };

NLOHMANN_JSON_SERIALIZE_ENUM(Result, {{NULLPTR, nullptr}, {TRUE, true}, {FALSE, false}})

// asdf
class Solution {
public:
    Trie* obj = nullptr;
};

void test(Solution& sol, const json& input, const json& output) {
    vector<string> ops = input["ops"].get<vector<string>>();
    vector<vector<string>> params = input["params"].get<vector<vector<string>>>();
    vector<Result> expecteds = output.get<vector<Result>>();

    for (size_t i = 0; i < ops.size(); ++i) {
        string op = ops[i];
        vector<string> param = params[i];
        Result expected = expecteds[i];

        if (op == "Trie") {
            sol.obj = new Trie();
            CHECK_EQ(expected, NULLPTR);  // make sure test data isn't bugged
        } else if (op == "insert") {
            sol.obj->insert(param[0]);
            CHECK_EQ(expected, NULLPTR);  // make sure test data isn't bugged
        } else if (op == "search") {
            bool result = sol.obj->search(param[0]);
            CHECK_EQ(result, (bool)expected);
        } else if (op == "startsWith") {
            bool result = sol.obj->startsWith(param[0]);
            CHECK_EQ(result, (bool)expected);
        } else FAIL("invalid op");
    }

    delete sol.obj;
}

// asdf
TEST_CASE("") {
    TEST(208);
}