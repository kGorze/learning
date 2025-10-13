#include <vector>
#include <iostream>

int evenNumberBitwiseORs(std::vector<int>& nums) {
        int result = 0;
        for(int num : nums){
            if(num % 2 == 0){
                result |= num;
            }
        }
        return result;
}

int main(){
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << evenNumberBitwiseORs(nums) << std::endl;
    return 0;
}
