//aim for the O(n) time and O(1) space
#include <vector>
#include <iostream>
#include <algorithm>

int maxArea(std::vector<int>& height){
    int left = 0;
    int right = height.size() - 1;
    int maxArea = 0;
    while(left < right){
        int area = std::min(height[left], height[right]) * (right - left);
        maxArea = std::max(maxArea, area);
        if(height[left] < height[right]){
            left++;
        }else{
            right--;
        }
    }
    return maxArea;
};


int main(){
    std::vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    std::vector<int> height2 = {1, 1};
    std::cout << maxArea(height) << std::endl;
    std::cout << maxArea(height2) << std::endl;
    return 0;
}