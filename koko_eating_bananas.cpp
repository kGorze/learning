#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
int minEatingSpeed(std::vector<int>& piles, int h) {
    //whats the upper bound of the speed? if the time is always bigger than the number of piles
    //upper bound is the max of the piles
    int max_of_pile = *std::max_element(piles.begin(), piles.end());
    std::cout<<"max of the piles: "<< max_of_pile << std::endl;
    std::cout<< "ceil of the max of the piles / h: "<< std::ceil(max_of_pile/h) << std::endl;

    return 1;
}

int main(){
    std::vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    std::cout << minEatingSpeed(piles, h) << std::endl;
    return 0;
}