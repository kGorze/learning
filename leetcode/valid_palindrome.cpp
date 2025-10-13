#include <string>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <regex>


bool isPalindrome(std::string s){
    for(char &c : s){
        c = std::tolower(c);
    }
    s = std::regex_replace(s, std::regex("[^a-zA-Z0-9]"), "");
    int left = 0;
    int right = s.size() - 1;
    while(left < right){
        if(s[left] != s[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}


int main(){
    std::string s = "A man, a plan, a canal: Panama";
    std::cout << isPalindrome(s) << std::endl;
    return 0;
}