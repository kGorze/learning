#include <string>
#include <iostream>
#include <unordered_map>


std::string fractionToDecimal(int numerator, int denominator){
    if (numerator == 0) return "0";

    bool neg = ((long long)numerator < 0) ^ ((long long)denominator < 0);

    long long n = llabs((long long)numerator);
    long long d = llabs((long long)denominator);


    long long integer_part = n / d;
    long long remainder    = n % d;

    std::string answer;
    if (neg && (integer_part != 0 || remainder != 0)) answer.push_back('-');
    answer += std::to_string(integer_part);

    if (remainder == 0) return answer;

    answer.push_back('.');

    std::unordered_map<long long, size_t> remainder_index; 
    std::string fraction_part;

    while (remainder != 0) {
        if (remainder_index.count(remainder)) {
            size_t idx = remainder_index[remainder];
            return answer + fraction_part.substr(0, idx) + "(" + fraction_part.substr(idx) + ")";
        }
        remainder_index[remainder] = fraction_part.size();
        remainder *= 10;
        fraction_part.push_back(char('0' + (remainder / d)));
        remainder %= d;
    }

    return answer + fraction_part;
}






int main(){
    std::cout << fractionToDecimal(-1, -2147483648) << std::endl;
    return 0;
}