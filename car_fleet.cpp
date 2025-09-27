#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
    //can we see that matehamtically when the cars come up at the same time. without that obsticle that the cars need to be behind each other
    std::vector<double> time;
    std::vector<std::pair<int, double>> time_pair;
    for(int i = 0; i < position.size(); i++){
        double time_to_target = static_cast<double>(target - position[i]) / static_cast<double>(speed[i]);
        time.push_back(time_to_target);
    }
    for(int i = 0; i< time.size(); i++){
        time_pair.push_back(std::make_pair(position[i], time[i]));
    }
    std::sort(time_pair.begin(), time_pair.end(), [](const std::pair<double, double>& a, const std::pair<double, double>& b){
        return a.first > b.first;
    });
    int fleets = 0;
    double max_time = -1.0;
    for(int i = 0; i< time_pair.size(); i++){
        if(time_pair[i].second > max_time){
            max_time = time_pair[i].second;
            fleets++;
    }
    }
    return fleets;
}

int main(){
    int target = 12;
    std::vector<int> position = {10, 8, 0, 5, 3};
    std::vector<int> speed = {2, 4, 1, 1, 3};
    std::cout << carFleet(target, position, speed) << std::endl;
    return 0;
}
