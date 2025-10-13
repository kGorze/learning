#include <vector>
#include <stack>
#include <iostream>
std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
 std::stack<int> st;
 std::vector<int> results(temperatures.size(), 0);
 for(int i = 0; i < temperatures.size(); i++){
    while(!st.empty() && temperatures[i] > temperatures[st.top()]){
        results[st.top()] = i - st.top();
        st.pop();
    }
    st.push(i);
 }
 return results;
 }


 int main(){
    std::vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    std::vector<int> results = dailyTemperatures(temperatures);
    for(int i = 0; i < results.size(); i++){
        std::cout << results[i] << " ";
    }
    std::cout << std::endl;
    return 0;       
 }