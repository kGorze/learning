//aim for the O(n) time and O(n) space
#include <vector>
#include <iostream>
#include <algorithm>


int trap(std::vector<int>& height){
    if(height.size() == 0){
        return 0;
    }
int left = 0;
int right = height.size() - 1;
int leftMax = height[left];
int rightMax = height[right];
int water = 0;
while(left < right){
    if(leftMax < rightMax){
        left++;
        leftMax = std::max(leftMax, height[left]);
        water += leftMax - height[left];
    }
    else{
        right--;
        rightMax = std::max(rightMax, height[right]);
        water += rightMax - height[right];
    }
}
return water;
}

int main(){
    std::vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    std::cout << trap(height) << std::endl;
    return 0;
}