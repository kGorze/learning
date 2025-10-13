#include <vector>
#include <iostream>
using namespace std;

void backtrack(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result){
    if(index == nums.size()){
        result.push_back(current);
        return;
    }
    current.push_back(nums[index]);
    backtrack(nums, index + 1, current, result);
    current.pop_back();
    backtrack(nums, index + 1, current, result);
}

vector<vector<int>> subsets(vector<int>& nums) {
        //should aim for the O(n*2^n) time and O(n) space solution
        vector<int> current;
        vector<vector<int>> result;
        backtrack(nums, 0, current, result);
        return result;
}

int main(){
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = subsets(nums);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}