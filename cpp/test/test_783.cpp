#include <optional>
#include <queue>
#include <vector>

#include "../src/code_783.cpp"
#include "cpp_deps/boilerplate.hpp"

using namespace std;

using Value = optional<int>;

void clear(TreeNode*& root) {
    if (root) {
        clear(root->left);
        clear(root->right);
        delete root;
        root = nullptr;
    }
}

TreeNode* from_array(const vector<Value>& vec) {
    if (vec.empty() || !vec[0].has_value()) return nullptr;

    auto* root = new TreeNode(vec[0].value());
    queue<TreeNode*> q({root});

    for (size_t idx = 1; idx < vec.size(); idx += 2) {
        if (vec[idx].has_value()) {
            q.front()->left = new TreeNode(vec[idx].value());
            q.push(q.front()->left);
        }

        if (idx + 1 < vec.size() && vec[idx + 1].has_value()) {
            q.front()->right = new TreeNode(vec[idx + 1].value());
            q.push(q.front()->right);
        }

        q.pop();
    }

    return root;
}

vector<Value> get_values(const json& input) {
    vector<Value> res(input.size());

    for (size_t i = 0; i < input.size(); ++i) {
        if (!input[i].is_null()) res[i].emplace(input[i].get<int>());
    }

    return res;
}

void test(Solution& sol, const json& input, const json& output) {
    TreeNode* root = from_array(get_values(input["root"]));
    int expected = output.get<int>();
    int result = sol.minDiffInBST(root);
    CHECK_EQ(result, expected);
    clear(root);
}

TEST_CASE("") {
    TEST(783);
}