#include <vector>
#include <cmath>
#include <iostream>

int findDuplicate(std::vector<int>& nums) {
    
    for(int i = 0; i < nums.size(); i++){
    int v = std::abs(nums[i]);
    int index = v - 1;
    if(nums[index] < 0){
        return v;
    }
    nums[index] = -nums[index];
    }
    return -1;
}

int main(){
    std::vector<int> nums = {1, 3, 4, 2, 2};
    std::cout << findDuplicate(nums) << std::endl;
    return 0;
}