#ifndef BOILERPLATE_H
#define BOILERPLATE_H

#include <fstream>
#include <string>

#include "doctest.hpp"
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

// asdf
class Solution;

json get_json(const int n) {
    ifstream test_file("../data/testcases/test_" + to_string(n) + ".json");
    json tests;
    test_file >> tests;
    return tests;
}

void test(Solution& sol, const json& input, const json& output);

#define TEST(n)                                                                                    \
    {                                                                                              \
        json tests = get_json(n);                                                                  \
                                                                                                   \
        for (json::iterator it = tests.begin(); it != tests.end(); ++it) {                         \
            const json& test_case = *it;                                                           \
            const json& input = test_case["input"];                                                \
            const json& output = test_case["output"];                                              \
            string comments = "\n";                                                                \
            comments += test_case.contains("comments") ? test_case["comments"].get<string>() : ""; \
            Solution sol;                                                                          \
            INFO("TEST CASE " << (it - tests.begin()));                                            \
            INFO(comments);                                                                        \
            /* problem specific */                                                                 \
            test(sol, input, output);                                                              \
        }                                                                                          \
    }

#endif