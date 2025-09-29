#include <string>
#include <unordered_map>
#include <iostream>

std::string minWindow(std::string s, std::string t) {
    //two strings s(m) and t(n)
    //minimum window substring of s(m) that every characted in t(n) is included
    if(s.size() < t.size()) return "";
    std::unordered_map<char,int> need, window;
    for(char c : t) need[c]++;
    int left = 0;
    int required = (int)need.size();
    int formed = 0;
    int best_length = INT_MAX, best_left = 0;


    for(int right = 0; right < s.size(); ++right){
        char c = s[right];
        window[c]++;
        if(need.find(c) != need.end() && window[c] == need[c]){
            formed++;
        }

        
        while(left <= right && formed == required){
            if(right - left + 1 < best_length){
                best_length = right - left + 1;
                best_left = left;
            }
            char left_char = s[left];
            window[left_char]--;
            if(need.find(left_char) != need.end() && window[left_char] < need[left_char]){
                formed--;
            }
            left++;
        }
    }
    return best_length == INT_MAX ? "" : s.substr(best_left, best_length);
}

int main(){
    std::string s = "ADOBECODEBANC";
    std::string t = "ABC";
    std::cout << minWindow(s, t) << std::endl;
    return 0;
}