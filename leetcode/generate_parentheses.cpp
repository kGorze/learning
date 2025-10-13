#include <vector>
#include <string>
#include <iostream>

void gen(int openN, int closeN, int n, std::string& curr, std::vector<std::string>& out) {
    if (openN == n && closeN == n) {
        out.push_back(curr);
        return;
    }
    if (openN < n) {
        curr.push_back('(');
        gen(openN + 1, closeN, n, curr, out);
        curr.pop_back();
    }
    if (closeN < openN) {
        curr.push_back(')');
        gen(openN, closeN + 1, n, curr, out);
        curr.pop_back();
    }
}

std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> out;
    std::string curr;
    gen(0, 0, n, curr, out);
    return out;
}

int main() {
    int n = 3;
    auto res = generateParenthesis(n);
    for (const std::string& s : res) {
        std::cout << s << '\n';
    }
    return 0;
}