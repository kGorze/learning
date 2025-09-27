#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
bool canEat(const std::vector<int>& piles, int speed, int h){
    long long time = 0;
    for(int pile : piles){
        time += (pile + speed - 1) / speed; 
        if (time > h) return false;         
    }
    return time <= h;
}
int minEatingSpeed(std::vector<int>& piles, int h) {
    //whats the upper bound of the speed? if the time is always bigger than the number of piles
    //upper bound is the max of the piles
    int max_of_pile = *std::max_element(piles.begin(), piles.end());
    std::cout<<"max of the piles: "<< max_of_pile << std::endl;
    int left = 1;
    int right = max_of_pile;
    while(left <= right){
        int mid = left + (right - left)/2;
        if(canEat(piles, mid, h)){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return left;
}

int main(){
    std::vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    std::cout << minEatingSpeed(piles, h) << std::endl;
    return 0;
}