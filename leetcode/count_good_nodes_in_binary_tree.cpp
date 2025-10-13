#include "tree.h"
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

void dfs(TreeNode* root, int max_val, int& count){
    if(root == nullptr) return;
    if(root->val >= max_val){
        count++;
        max_val = root->val;
    }
    dfs(root->left, max_val, count);
    dfs(root->right, max_val, count);
}

int goodNodes(TreeNode* root) {
    int count = 0;
    dfs(root, root->val, count);
    return count;
}

int main(){
    TreeNode* root = new TreeNode(3, new TreeNode(1, new TreeNode(3), new TreeNode(4)), new TreeNode(4, new TreeNode(1), new TreeNode(5)));
    std::cout << goodNodes(root) << std::endl;
    return 0;
}