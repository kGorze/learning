#include <vector>
#include <iostream>
#include <climits>

class MinStack {
    public:
        std::vector<int> values;
        int minimum;

        MinStack() {
            values = std::vector<int>();
            minimum = INT_MAX;
        }
        
        void push(int val) {
            values.push_back(val);
            if(val < minimum){
                minimum = val;
            }

        }
        
        void pop() {
            if(values.back() == minimum){
                minimum = INT_MAX;
                for(int i = 0; i < values.size() - 1; i++){
                    if(values[i] < minimum){
                        minimum = values[i];
                    }
                }
                values.pop_back();
            }
            else{
                values.pop_back();
            }
        }
        
        int top() {
            return values.back();
        }
        
        int getMin() {
            return minimum;
        }
    };


    int main(){
        MinStack minStack;
        minStack.push(-2);
        minStack.push(0);
        minStack.push(-3);
        return 0;
    }