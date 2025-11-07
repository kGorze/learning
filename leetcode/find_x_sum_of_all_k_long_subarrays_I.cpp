#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

int compute_xsum(const unordered_map<int,int>& freq, int x) {
    vector<pair<int,int>> v(freq.begin(), freq.end());
    sort(v.begin(), v.end(), [](const pair<int,int>& a, const pair<int,int>& b){
        if (a.second != b.second) return a.second > b.second;
        return a.first > b.first;                              
    });
    int take = min<int>(x, static_cast<int>(v.size()));
    long long xsum = 0;
    for (int i = 0; i < take; ++i) {
        xsum += 1LL * v[i].first * v[i].second;
    }
    return static_cast<int>(xsum);
}
vector<int> findXSum(vector<int>& nums, int k, int x) {
    vector<int> result;
    unordered_map<int,int> frequencies; //(num, frequency)
    for (int i = 0; i < k; ++i) {
        frequencies[nums[i]] += 1;
    }
    result.push_back(compute_xsum(frequencies, x));
    for (int i = k; i < static_cast<int>(nums.size()); ++i) {
        frequencies[nums[i]] += 1;
        int oldv = nums[i - k];
        if (--frequencies[oldv] == 0) frequencies.erase(oldv);
        result.push_back(compute_xsum(frequencies, x));
    }
    return result;
}

int main(){
    vector<int> nums = {1,1,2,2,3,4,2,3};
    int k = 6;
    int x = 2;
    vector<int> result = findXSum(nums, k, x);
    for(int i = 0; i < result.size(); ++i){
        cout << result[i] << " ";
    }
    return 0;
}