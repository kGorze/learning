#include <string>
#include <unordered_map>
#include <iostream>


bool checkInclusion(std::string s1, std::string s2) {
        if (s1.size() > s2.size()) return false;
        std::unordered_map<char,int> need, window;
        for(char c : s1)need[c]++;
        int left = 0;
        int right = 0;
        while(right < s2.length()){
            window[s2[right]]++;
            right++;
            if(right - left == s1.length()){
                if(need == window){
                    return true;
                }
                if(--window[s2[left]] == 0) window.erase(s2[left]);
                left++;
            }
        }
        return false;
}

int main(){
    std::string s1 = "ab";
    std::string s2 = "eidbaooo";
    std::cout << checkInclusion(s1, s2) << std::endl;
    return 0;
}