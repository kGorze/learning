//aim for the O(n) time and O(n) space

#include <vector>
#include <string>
#include <iostream>


int evalRPN(std::vector<std::string>& tokens){
    std::vector<int> st;
    for (const std::string& tok : tokens){
        if (tok=="+" || tok=="-" || tok=="*" || tok=="/"){
            if (st.size() < 2) return 0;                
            int b = st.back(); st.pop_back();            
            int a = st.back(); st.pop_back();            
            long long r = 0;                             
            if (tok=="+")      r = (long long)a + b;
            else if (tok=="-") r = (long long)a - b;
            else if (tok=="*") r = (long long)a * b;
            else {                                       
                if (b == 0) return 0;                    
                r = a / b;                               
            }
            st.push_back((int)r);
        } else {
            st.push_back(std::stoi(tok));
        }
    }
    return st.size()==1 ? st.back() : 0;       
}


int main(){
    std::vector<std::string> tokens = {"2", "1", "+", "3", "*"};
    std::cout << evalRPN(tokens) << std::endl;
    return 0;
}