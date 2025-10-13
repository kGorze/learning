#include <vector>
#include <string>
#include <iostream>

using namespace std;

void backtrack(string digits, int index, string current, vector<string>& result, vector<string>& mapping){
    if(index == digits.size()){
        result.push_back(current);
        return;
    }
    string letters = mapping[digits[index] - '0'];
    for(char letter : letters){
        backtrack(digits, index + 1, current + letter, result, mapping);
    }
    return;
}

vector<string> letterCombinations(string digits) {
    if(digits.empty()) return {};
    vector<string> result; 
    vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    backtrack(digits, 0, "", result, mapping);
    return result;
}



int main(){
    string digits = "23";
    vector<string> result = letterCombinations(digits);
    for(string s : result){
        cout << s << endl;
    }
    return 0;
}