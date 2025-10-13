    #include <vector>
    #include <algorithm>
    #include <iostream>
    int largestPerimeter(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for(int i = nums.size() - 1; i >= 2; i--){
            if(nums[i] < nums[i-1] + nums[i-2]){
                return nums[i] + nums[i-1] + nums[i-2];
            }
        }
        return 0;
    }

    int main(){
        std::vector<int> nums = {2, 1, 2};
        std::vector<int> nums2 = {1,2,1,10};
        std::cout << largestPerimeter(nums) << std::endl;
        std::cout << largestPerimeter(nums2) << std::endl;
        return 0;
    }