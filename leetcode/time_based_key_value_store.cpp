#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>



class TimeMap {
    public:
        std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> store;

        TimeMap() = default;
        
        void set(std::string key, std::string value, int timestamp) {
            //should aim for the O(1) time complexity
            auto& vec = store[key];

            if(!vec.empty() && vec.back().first <= timestamp){
                auto it = std::lower_bound(vec.begin(), vec.end(), std::make_pair(timestamp, value), [](const auto& a, const auto& b){
                    return a.first < b.first;
                });
                vec.insert(it, std::make_pair(timestamp, value));
            }
            vec.push_back(std::make_pair(timestamp, value));
        }
        
        std::string get(std::string key, int timestamp) {
            //should aim for the O(logn) time complexity and O(m*n) space, n is the total number of values associated with a key, and m is the total number of keys.
            auto it = store.find(key);
            if (it == store.end()) return "";
            const auto& vec = it->second;
            int l = 0, r = (int)vec.size() - 1, ans = -1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (vec[m].first <= timestamp) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ans == -1 ? "" : vec[ans].second;
        }
    };
    
    /**
     * Your TimeMap object will be instantiated and called as such:
     * TimeMap* obj = new TimeMap();
     * obj->set(key,value,timestamp);
     * string param_2 = obj->get(key,timestamp);
     */

int main(){
    TimeMap timeMap;
    timeMap.set("foo", "bar", 1);
    std::cout << timeMap.get("foo", 1) << std::endl;
    std::cout << timeMap.get("foo", 3) << std::endl;
    timeMap.set("foo", "bar2", 4);
    std::cout << timeMap.get("foo", 4) << std::endl;
    std::cout << timeMap.get("foo", 5) << std::endl;
    return 0;
}