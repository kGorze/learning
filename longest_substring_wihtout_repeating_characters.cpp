#include <string>
#include <unordered_set>
#include <iostream>
#include <algorithm>


int lengthOfLongestSubstring(std::string s) {
    int left = 0;
    int right = 0;
    int max_length = 0;
    std::unordered_set<char> char_set;
    while(right < s.size()){
        if(char_set.find(s[right]) == char_set.end()){
            char_set.insert(s[right]);
            right++;
            max_length = std::max(max_length, right - left);
        }else{
            char_set.erase(s[left]);
            left++;
        }
    }
    return max_length;
}

int main(){
    std::string s = "abcabcbb";
    std::cout << lengthOfLongestSubstring(s) << std::endl;
    return 0;
}