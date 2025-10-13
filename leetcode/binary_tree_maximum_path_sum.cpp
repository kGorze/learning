#include "tree.h"
#include <algorithm>
#include <iostream>
#include <climits>


int dfs(TreeNode* root, int& max_sum){
    if(root == nullptr) return 0;
    int left_max = dfs(root->left, max_sum);
    int right_max = dfs(root->right, max_sum);
    left_max = std::max(left_max, 0);
    right_max = std::max(right_max, 0);
    
    max_sum = std::max(max_sum, root->val + left_max + right_max);
    return root->val + std::max(left_max, right_max);
    
}

int maxPathSum(TreeNode* root) {
    //I should aim for the O(n) time and O(n) space solution
    if(root == nullptr) return 0;
int max_sum = INT_MIN;
(void)dfs(root, max_sum);
return max_sum;

}

int main(){
    TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    std::cout << maxPathSum(root) << std::endl;
    return 0;
}