#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int jump(vector<int>& nums) {
    int n = nums.size();
    if(n <= 1) return 0;
    int jumps = 0;
    int end = 0;
    int farthest = 0;
    for(int i = 0; i < n - 1; ++i){
        farthest = max(farthest, i + nums[i]);
        if(i == end){
            jumps++;
            end = farthest;
            if(end >= n - 1) break;
        }
    }
    return jumps;
}

int main(){
    vector<int> nums = {2, 3, 1, 1, 4};
    std::cout << jump(nums) << std::endl;
    return 0;
}