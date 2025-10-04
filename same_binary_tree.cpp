#include "tree.h"
#include <iostream>

int dfs(TreeNode* p, TreeNode* q){
if(p == nullptr && q == nullptr) return true;
if(p == nullptr || q == nullptr) return false;
if(p->val != q->val) return false;
return dfs(p->left, q->left) && dfs(p->right, q->right);
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    return dfs(p, q);
}

int main(){
    TreeNode* p = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* q = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    std::cout << isSameTree(p, q) << std::endl;
    return 0;
}