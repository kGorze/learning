#include "tree.h"
#include <iostream>
using namespace std;

bool dfs(TreeNode* root, const TreeNode*& prev){
//basecase is the null pointer
if(root == nullptr) return true;
//if the left subtree is not a valid BST, return false
if(!dfs(root->left, prev)) return false;
//if the current node is less than the previous node, return false
if(prev && root->val <= prev->val) return false;
//update the previous node
prev = root;
//if the right subtree is not a valid BST, return false
return dfs(root->right, prev);
}

bool isValidBST(TreeNode* root) {
    const TreeNode* prev = nullptr;
    return dfs(root, prev);
}

int main(){
    TreeNode* root = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    std::cout << isValidBST(root) << std::endl;
    return 0;
}