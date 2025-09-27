#include <vector>
#include <iostream>
#include <algorithm>
std::vector<int> twoSum(std::vector<int>& numbers, int target){
    int left = 0;
    int right = numbers.size() - 1;
    while(left < right){
        int sum = numbers[left] + numbers[right];
        if(sum == target){
            return {left + 1, right + 1};
        }else if(sum < target){
            left++;
        }else{
            right--;
        }
    }
    return {};
}

int main(){
    std::vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> result = twoSum(numbers, target);
    std::cout << result[0] << " " << result[1] << std::endl;
    return 0;
}