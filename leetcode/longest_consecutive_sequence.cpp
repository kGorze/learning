#include <vector>
#include <unordered_set>
#include <iostream>
#include <algorithm>

int longestConsecutive(std::vector<int>& nums){
    std::unordered_set<int> num_set;
    int longest_streak = 0;
    for(int num: nums){
        num_set.insert(num);
    }
    for(int value : num_set){
        int num = value;
        if(num_set.find(num-1) != num_set.end()){
            continue;
        }
        int current_num = num;
        int current_streak = 1;
        while(num_set.find(current_num+1) != num_set.end()){
            current_num += 1;
            current_streak += 1;
        }
        if(current_streak > longest_streak){
            longest_streak = current_streak;
        }
    }
    return longest_streak;
}

int main(){
    std::vector<int> nums = {100, 4, 200, 1, 3, 2};
    std::cout << longestConsecutive(nums) << std::endl;
    return 0;

}