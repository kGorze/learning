#include "tree.h"
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<vector<int>> levelOrder(const TreeNode* root){
    vector<vector<int>> result;
    if(!root) return result;
    queue<const TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        size_t level_size = q.size();
        vector<int> level;
        level.reserve(level_size);

        for(int i = 0; i < level_size; i++){
            const TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        result.push_back(level);
    }
    return result;
}



void dfs(TreeNode* root, vector<vector<int>>& result, int level){
if(root == nullptr) return;
if(result.size() == level) result.push_back(vector<int>());
result[level].push_back(root->val);
dfs(root->left, result, level + 1);
dfs(root->right, result, level + 1);



}
vector<vector<int>> levelOrder(TreeNode* root) {
//should aim for the O(n) time and O(n) space
vector<vector<int>> result;
bfs(root, result);
return result;
}


int main(){
    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3, new TreeNode(6), new TreeNode(7)));
    vector<vector<int>> result = levelOrder(root);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}