#include <vector>
#include <iostream>

int search(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int switch_point = 0;
    while(left <= right){
        int mid = left + (right - left)/2;
        if(nums[mid] == target){
            return mid;
        }
        else if(nums[left] <= nums[mid]){
            if(target >= nums[left] && target < nums[mid]){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        else{
            if(target > nums[mid] && target <= nums[right]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
    }
    return -1;
}

int main(){
    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    std::cout << search(nums, target) << std::endl;
    return 0;
}
