#include "boilerplate.h"

json get_json(const string& fp) {
    ifstream test_file(fp);
    json tests;
    test_file >> tests;
    return tests;
}