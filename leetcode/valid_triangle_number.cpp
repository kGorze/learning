#include <vector>
#include <iostream>
#include <algorithm>    

int triangleNumber(std::vector<int>& nums) {
    int count = 0;
    sort(nums.begin(), nums.end());
    int right = nums.size() - 1;
    for(right; right >= 2 ; --right){
        if(nums[right] == 0) continue;
        int left = 0;
        int mid = right - 1;
        while(left < mid){
            if(nums[left] + nums[mid] > nums[right]){
                count += mid - left;
                mid--;
            }
            else{
                left++;
            }
        }
    }
    
    return count;
}

int main(){
    std::vector<int> nums = {2,2,3,4};
    std::cout << triangleNumber(nums) << std::endl;
    return 0;
}
