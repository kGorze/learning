#include "tree.h"
#include <iostream>

bool dfs(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& result) {
    if (root == nullptr) return false;

    bool left  = dfs(root->left,  p, q, result);
    bool right = dfs(root->right, p, q, result);
    bool self  = (root == p || root == q);

    if (!result && (int)left + (int)right + (int)self >= 2) {
        result = root;
    }
    return left || right || self;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* result = nullptr;
    dfs(root, p, q, result);
    return result;
}

int main() {
    TreeNode* root = new TreeNode(
        3,
        new TreeNode(5,
            new TreeNode(6),
            new TreeNode(2, new TreeNode(7), new TreeNode(4))
        ),
        new TreeNode(1, new TreeNode(0), new TreeNode(8))
    );
    TreeNode* p = root->left->right->right; // 4
    TreeNode* q = root->right->right;       // 8
    TreeNode* lca = lowestCommonAncestor(root, p, q);
    if (lca) std::cout << lca->val << std::endl; // oczekiwane: 3
    return 0;
}