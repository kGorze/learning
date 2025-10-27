#include <string>
#include <iostream>
using namespace std;

string addBinary(string a, string b) {
 int i = a.size() - 1;
 int j = b.size() - 1;
 int carry = 0;
 string result = "";
 while(i >= 0 || j >= 0 || carry){
    if(i >= 0) carry += a[i--] - '0';
    if(j >= 0) carry += b[j--] - '0';
    result = char(carry % 2 + '0') + result;
    carry /= 2;
 }
    return result;  
}

int main(){
    string a = "1";
    string b = "11";
    cout << addBinary(a, b) << endl;
    return 0;
}