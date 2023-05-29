#ifndef BOILERPLATE_H
#define BOILERPLATE_H

#include <fstream>
#include <string>

#include "doctest.h"
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

class Solution;

json get_json(const string& fp);

void test(Solution& sol, const json& input, const json& output);

#define TEST(fp)                                                           \
    {                                                                      \
        json tests = get_json(fp);                                         \
                                                                           \
        for (json::iterator it = tests.begin(); it != tests.end(); ++it) { \
            const json& test_case = *it;                                   \
            const json& input = test_case["input"];                        \
            const json& output = test_case["output"];                      \
            Solution sol;                                                  \
            INFO("TEST CASE " << (it - tests.begin()));                    \
                                                                           \
            /* problem specific */                                         \
            test(sol, input, output);                                      \
        }                                                                  \
    }

#endif