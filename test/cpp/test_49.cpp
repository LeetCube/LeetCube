#include "../../src/cpp/code_49.cpp"
#include "cpp_deps/boilerplate.h"

void test(Solution& sol, const json& input, const json& output) {
    vector<string> strs = input["strs"].get<vector<string>>();
    vector<vector<string>> expected = output.get<vector<vector<string>>>();
    vector<vector<string>> result = sol.groupAnagrams(strs);

    for (auto& v : result) sort(v.begin(), v.end());

    sort(result.begin(), result.end(), [](const vector<string>& a, const vector<string>& b) {
        if (a.size() < b.size()) return true;
        else if (b.size() < a.size()) return false;
        else return a < b;
    });

    CHECK_EQ(result, expected);
}

TEST_CASE("") {
    TEST("test/test_json/test_49.json");
}