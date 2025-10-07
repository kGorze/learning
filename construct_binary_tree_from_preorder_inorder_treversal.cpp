#include "tree.h"
using namespace std;
#include <vector>
#include <unordered_map>


TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int preorder_start, int preorder_end, int inorder_start, int inorder_end, unordered_map<int, int>& inorder_map){
    if(preorder_start > preorder_end || inorder_start > inorder_end) return nullptr;
    int root_val = preorder[preorder_start];
    int root_index = inorder_map[root_val];
    int left_size = root_index - inorder_start;
    TreeNode* root = new TreeNode(root_val);
    root->left = buildTreeHelper(preorder, inorder, preorder_start + 1, preorder_start + left_size, inorder_start, root_index - 1, inorder_map);
    root->right = buildTreeHelper(preorder, inorder, preorder_start + left_size + 1, preorder_end, root_index + 1, inorder_end, inorder_map);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    //should include the O(n) time and O(n) space solution
    unordered_map<int, int> inorder_map;
    for(int i = 0; i < inorder.size(); i++){
        inorder_map[inorder[i]] = i;
    }
    return buildTreeHelper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1, inorder_map);
}

int main(){
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* root = buildTree(preorder, inorder);
    return 0;
}