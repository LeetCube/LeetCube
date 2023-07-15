#include <algorithm>
#include <limits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    void in_order(TreeNode* node, TreeNode*& prev, int& min_diff) {
        if (!node) return;

        in_order(node->left, prev, min_diff);

        if (prev) min_diff = min(min_diff, node->val - prev->val);

        prev = node;
        in_order(node->right, prev, min_diff);
    }

public:
    /**
        Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

        @pre The number of nodes in the tree is in the range [2, 100].
        @pre 0 <= Node.val <= 10^5
    */
    int minDiffInBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        int min_diff = numeric_limits<int>::max();
        in_order(root, prev, min_diff);
        return min_diff;
    }
};
