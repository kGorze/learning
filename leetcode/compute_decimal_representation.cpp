#include <vector>
#include <iostream>
#include <cmath>
std::vector<int> decimalRepresentation(int n) {
    std::vector<int> result;
    std::vector<int> number; 
    int size = 0;
    int temp = n;
    long power = 1;
    while(temp > 0){
        temp /= 10;
        size++;
    }
    while(n > 0){
        long digit = n % 10;
        digit *= power;
        if(digit != 0) result.push_back(digit);
        n /= 10;
        size--;
        power *= 10;
    }

    reverse(result.begin(), result.end());
    return result;
    }

    int main(){
        int n = 123;
        std::vector<int> result = decimalRepresentation(n);
        for(int i = 0; i < result.size(); i++){
            std::cout << result[i] << " ";
        }
        return 0;
    }