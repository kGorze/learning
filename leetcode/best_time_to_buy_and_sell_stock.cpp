#include <vector>
#include <iostream>

int maxProfit(std::vector<int>& prices) {
    //should aim for the O(n) time and O(1) space
    //profit = sell - buy
    int max_profit = 0;
    int current_profit = prices[0];
    int left = 0;
    int right = 1;
    while(right < prices.size()){
        current_profit = prices[right] - prices[left];
        if(current_profit > max_profit) max_profit = current_profit;
        if(prices[right] < prices[left]) left = right;
        right++;
    }
    return max_profit;
}

int main(){
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    std::cout << maxProfit(prices) << std::endl;
    return 0;
}
