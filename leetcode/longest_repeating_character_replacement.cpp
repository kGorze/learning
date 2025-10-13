#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>

int maxElement(std::unordered_map<char, int>& char_count){
    return std::max_element(char_count.begin(), char_count.end(), [](const std::pair<char, int>& a, const std::pair<char, int>& b){
        return a.second < b.second;
    })->second;
}

int characterReplacement(string s, int k) {
    unordered_map<char,int> cnt;
    int left = 0, maxLen = 0, maxFreq = 0;

    for (int right = 0; right < (int)s.size(); ++right) {
        maxFreq = max(maxFreq, ++cnt[s[right]]);
        while ((right - left + 1) - maxFreq > k) {
            --cnt[s[left]];
            ++left;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

int main(){
    std::string s = "AABABBA";
    int k = 2;
    std::cout << characterReplacement(s, k) << std::endl;
    return 0;
}