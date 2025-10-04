#include "tree.h"
#include <algorithm>
#include <cmath>
#include <iostream>

int dfs(TreeNode* root) {
    if(root == nullptr) return 0;
    int leftDepth = dfs(root->left);
    int rightDepth = dfs(root->right);
    if(leftDepth == -1 || rightDepth == -1 || std::abs(leftDepth - rightDepth) > 1) return -1;
    return std::max(leftDepth, rightDepth) + 1;
}

bool isBalanced(TreeNode* root) {
    return dfs(root) != -1;
}

int main(){
    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));
    std::cout << isBalanced(root) << std::endl;
    return 0;
}