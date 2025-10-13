#include "tree.h"
#include <vector>
#include <queue>
#include <iostream>
using namespace std;



void bfs(TreeNode* root, vector<int>& result){
    if(!root) return;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        size_t level_size = q.size();
        for(int i = 0; i < level_size; i++){
            TreeNode* node = q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            if(i == level_size - 1) result.push_back(node->val);
        }
    }
};


vector<int> rightSideView(TreeNode* root) {
 //should aim for the O(n) time and O(n) space complexity
 vector<int> result;
 bfs(root, result);
 return result;
};


int main(){
    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3, new TreeNode(6), new TreeNode(7)));
    vector<int> result = rightSideView(root);
    for(int i = 0; i < result.size(); i++){
        std::cout << result[i] << " ";
    }
    return 0;
}