#include "tree.h"
#include <algorithm>
#include <iostream>

int dfs(TreeNode* root, int& diameter) {
    if(root == nullptr) return 0;
    int leftDepth = dfs(root->left, diameter);
    int rightDepth = dfs(root->right, diameter);
    diameter = std::max(diameter, leftDepth + rightDepth);
    return std::max(leftDepth, rightDepth) + 1;
}
int diameterOfBinaryTree(TreeNode* root) {
    //should aim for the O(n) time and O(n) space
    int diameter = 0;
    dfs(root, diameter);
    return diameter;
}

int main(){
    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));
    std::cout << diameterOfBinaryTree(root) << std::endl;
    return 0;
}