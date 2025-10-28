#include <vector>
#include <climits>
#include <iostream>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
 //why can't i just do the greedy algorithm and go from the largest amount and do the subtraction until i get to 0.
 //how do i do it in the dynamic programming way?
if(amount == 0) return 0; 
vector<int> dp(amount + 1, INT_MAX);
dp[0] = 0;

for(int a = 1; a<= amount; ++a){
    for(int c : coins){
        if(a - c >= 0 && dp[a - c] != INT_MAX){
            dp[a] = min(dp[a], dp[a - c] + 1);
        }
    }
}

return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main(){
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    std::cout << coinChange(coins, amount) << std::endl;
    return 0;
}