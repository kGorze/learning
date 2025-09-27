#include <vector>
#include <iostream>


int search(std::vector<int>& nums, int target) {
int left = 0;
int right = nums.size() - 1;
while(left <= right){
    int mid = left + (right - left)/2;
    if(nums[mid] == target)return mid;
    else if(nums[mid] < target) left = mid + 1;
    else right = mid - 1;
}
return -1;
}
int main(){
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 7;
    std::cout << search(nums, target) << std::endl;
    return 0;
}