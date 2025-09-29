#include <vector>
#include <deque>
#include <iostream>

std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
    std::vector<int> result;
    std::deque<int> window;
    for(int i = 0; i < nums.size(); ++i){
        while(!window.empty() && nums[window.back()] < nums[i]){
            window.pop_back();
        }
        window.push_back(i);
        if(window.front() == i - k){
            window.pop_front();
        }
        if(i >= k - 1){
            result.push_back(nums[window.front()]);
        }

    }
    return result;
}

int main(){
    std::vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    nums = {1,-1};
    k = 1;
    std::vector<int> result = maxSlidingWindow(nums, k);
    for(int i = 0; i < result.size(); ++i){
        std::cout << result[i] << " ";
    }
    return 0;
}