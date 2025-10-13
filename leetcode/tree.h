#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void dfs(TreeNode* root, std::vector<int>& result){
std::vector<bool> marked(false);
std::queue<TreeNode*> q;
while(!q.empty()){
    TreeNode* node = q.front();
    q.pop();
    if(marked[node->val]) continue;
    else{
        marked[node->val] = true;
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }
    result.push_back(node->val);
}
return result;
}