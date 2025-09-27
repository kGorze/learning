#include <vector>
#include <iostream>
#include <algorithm>

//O(N^2), O(1)
std::vector<std::vector<int>> threeSum(std::vector<int>& nums){
    std::vector<std::vector<int>> results;
    std::sort(nums.begin(), nums.end());
    int size = nums.size();
    for(int i = 0; i< size; i++){
        if(i > 0 && nums[i] == nums[i-1]){
            continue;
        }
        int left = i + 1;
        int right = size - 1;
        while(left < right){
            if(nums[i] == -(nums[left] + nums[right])){
            results.push_back({nums[i], nums[left], nums[right]});
            left++;
            while(left < right && nums[left] == nums[left-1]){
                left++;
            }
            }else if(nums[i] < -(nums[left] + nums[right])){
                left++;
            }else{
                right--;
            }
        }
    }
    return results;
};
int main(){
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> result = threeSum(nums);
    for(int i = 0; i< result.size(); i++){
        for(int j = 0; j< result[i].size(); j++){
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}