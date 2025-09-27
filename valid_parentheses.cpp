//aim for the O(n) time and O(n) space

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>





bool isValid(std::string s){
std::vector<char> open_parentheses = {'(', '[', '{'};
std::vector<char> stack;
for(char c : s){
    if(std::find(open_parentheses.begin(), open_parentheses.end(), c) != open_parentheses.end()){
        stack.push_back(c);
    }else{
        if(stack.empty()){
            return false;
        }
        char top = stack.back();
        if(c == ')' && top == '(' || c == ']' && top == '[' || c == '}' && top == '{'){
            stack.pop_back();
        }else{
            return false;
        }
    }
}
return stack.empty();
}

int main(){
    std::string s = "()";
    std::cout << isValid(s) << std::endl;
    return 0;
}
