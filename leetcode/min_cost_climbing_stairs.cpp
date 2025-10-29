
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int minCostClimbingStairs(std::vector<int>& cost) {

vector<int> dp(cost.size(), 0);
dp[0] = cost[0];
dp[1] = cost[1];
for(int i = 2; i < cost.size(); ++i){
dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
}
return min(dp[cost.size() - 1], dp[cost.size() - 2]);
}

int main(){
    vector<int> cost = {10, 15, 20};
    std::cout << minCostClimbingStairs(cost) << std::endl;
    return 0;
}