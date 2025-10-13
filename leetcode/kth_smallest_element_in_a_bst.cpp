#include "tree.h"
#include <iostream>
using namespace std;

void dfs(TreeNode* root, int& k, int& result){
    if(root == nullptr) return;
    dfs(root->left, k, result);
    if(--k == 0){ 
        result = root->val;
        return;
    }
    dfs(root->right, k, result);
}


int kthSmallest(TreeNode* root, int k) {
    //aim for the O(n) time and O(n) space
    int result = 0;
    dfs(root, k, result);
    return result;
}

int main(){
    TreeNode* root = new TreeNode(3, new TreeNode(1, new TreeNode(2), new TreeNode(4)), new TreeNode(5));
    std::cout << kthSmallest(root, 1) << std::endl;
    return 0;
}