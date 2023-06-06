struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    bool verify(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;
        if (!root || !subRoot) return false;
        return root->val == subRoot->val && verify(root->left, subRoot->left) && verify(root->right, subRoot->right);
    }

public:
    /**
        Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

        A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

        @pre The number of nodes in the root tree is in the range [1, 2000].
        @pre The number of nodes in the subRoot tree is in the range [1, 1000].
        @pre -10^4 <= root.val <= 10^4
        @pre -10^4 <= subRoot.val <= 10^4
    */
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root->val == subRoot->val) { return verify(root, subRoot); }

        return (root->left && isSubtree(root->left, subRoot)) || (root->right && isSubtree(root->right, subRoot));
    }
};