#include <optional>

#include "../src/code_572.cpp"
#include "cpp_deps/boilerplate.hpp"

using Value = optional<int>;

void clear(TreeNode*& root) {
    if (root) {
        clear(root->left);
        clear(root->right);
        delete root;
        root = nullptr;
    }
}

TreeNode* from_array(const vector<Value>& vec, size_t idx) {
    if (idx >= vec.size() || !vec[idx].has_value()) return nullptr;
    else return new TreeNode(vec[idx].value(), from_array(vec, 2 * idx + 1), from_array(vec, 2 * idx + 2));
}

vector<Value> get_results(const json& output) {
    vector<Value> res(output.size());

    for (size_t i = 0; i < output.size(); ++i) {
        if (!output[i].is_null()) res[i].emplace(output[i].get<int>());
    }

    return res;
}

void test(Solution& sol, const json& input, const json& output) {
    TreeNode* root = from_array(get_results(input["root"]), 0);
    TreeNode* subRoot = from_array(get_results(input["subRoot"]), 0);
    bool expected = output.get<bool>();
    bool result = sol.isSubtree(root, subRoot);
    CHECK_EQ(result, expected);
    clear(root);
    clear(subRoot);
}

// asdf
TEST_CASE("") {
    TEST(572);
}