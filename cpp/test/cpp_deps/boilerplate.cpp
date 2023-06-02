#include "boilerplate.hpp"

json get_json(const int n) {
    ifstream test_file("../data/testcases/test_" + to_string(n) + ".json");
    json tests;
    test_file >> tests;
    return tests;
}