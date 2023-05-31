#include <fstream>
#include <vector>

#include "../../src/cpp/code_208.cpp"
#include "cpp_deps/doctest.h"
#include "cpp_deps/json.hpp"

using json = nlohmann::json;
using namespace std;

enum Result { TRUE = true, FALSE = false, NULLPTR = -1 };

NLOHMANN_JSON_SERIALIZE_ENUM(Result, {{NULLPTR, nullptr}, {TRUE, true}, {FALSE, false}})

TEST_CASE("") {
    ifstream test_file("test/test_json/test_208.json");
    json tests;
    test_file >> tests;

    for (json::iterator it = tests.begin(); it != tests.end(); ++it) {
        const json& test_case = *it;
        const json& input = test_case["input"];
        const json& output = test_case["output"];
        Trie* obj;
        INFO("TEST CASE " << (it - tests.begin()));
        vector<string> ops = input["ops"].get<vector<string>>();
        vector<vector<string>> params = input["params"].get<vector<vector<string>>>();
        vector<Result> expecteds = output.get<vector<Result>>();

        for (size_t i = 0; i < ops.size(); ++i) {
            string op = ops[i];
            vector<string> param = params[i];
            Result expected = expecteds[i];

            if (op == "Trie") {
                obj = new Trie();
                CHECK_EQ(expected, NULLPTR);  // make sure test data isn't bugged
            } else if (op == "insert") {
                obj->insert(param[0]);
                CHECK_EQ(expected, NULLPTR);  // make sure test data isn't bugged
            } else if (op == "search") {
                bool result = obj->search(param[0]);
                CHECK_EQ(result, (bool)expected);
            } else if (op == "startsWith") {
                bool result = obj->startsWith(param[0]);
                CHECK_EQ(result, (bool)expected);
            } else FAIL("invalid op");
        }

        delete obj;
    }
}