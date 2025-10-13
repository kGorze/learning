#include "tree.h"

bool dfs(TreeNode* root, TreeNode* subRoot){
    if(root == nullptr && subRoot == nullptr) return true;
    if(root == nullptr || subRoot == nullptr) return false;
    if(root->val != subRoot->val) return false;
    return dfs(root->left, subRoot->left) && dfs(root->right, subRoot->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        //should aim for the O(n*m) time and O(n+m) space
        if(root == nullptr) return false;
        if(dfs(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

