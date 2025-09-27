#include <vector>
#include <iostream>
#include <algorithm>

int minimumTotal(std::vector<std::vector<int>>& triangle) {
    if (triangle.empty()) return 0;
    std::vector<int> dp = triangle.back(); 
    for (int i = (int)triangle.size() - 2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            dp[j] = triangle[i][j] + std::min(dp[j], dp[j+1]);
        }
    }
    return dp[0];
}

int main() {
    std::vector<std::vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    std::cout << minimumTotal(triangle) << '\n'; 
    return 0;
}