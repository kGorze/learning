#include "tree.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs_serialize(TreeNode* root, string& result){
    if(root == nullptr){
        result += "null,";
        return;
    }
    result += to_string(root->val) + ",";
    dfs_serialize(root->left, result);
    dfs_serialize(root->right, result);
    return;
}

TreeNode* dfs_deserialize(vector<string>& data_list, int& index){
    if(index >= data_list.size()) return nullptr;
    if(data_list[index] == "null"){
        index++;
        return nullptr;
    }
    TreeNode* root = new TreeNode(stoi(data_list[index++]));
    root->left = dfs_deserialize(data_list, index);
    root->right = dfs_deserialize(data_list, index);
    return root;
}

static string nextToken(const string& data, int& i){
    if (i >= (int)data.size()) return "";
    string tok;
    while (i < (int)data.size() && data[i] != ',') tok += data[i++];
    if (i < (int)data.size() && data[i] == ',') ++i; 
    return tok;
}

class Codec {
    public:
    
        string serialize(TreeNode* root) {
            string result = "";
            dfs_serialize(root, result);
            return result;
        }
    
        TreeNode* deserialize(string data) {

            vector<string> data_list;
            int s_pos = 0;
            while(s_pos < data.size()){
                data_list.push_back(nextToken(data, s_pos));
            }
            int t_index = 0;
            return dfs_deserialize(data_list, t_index);
        }
    };


    int main(){
        TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
        Codec codec;
        string serialized = codec.serialize(root);
        TreeNode* deserialized = codec.deserialize(serialized);
        std::cout << deserialized->val << std::endl;
        return 0;
    }