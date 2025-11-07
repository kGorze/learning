#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;


long long compute_xsum_from_counts(const unordered_map<int,int>& ctr, int x) {
    vector<pair<int,int>> bucket;
    for (const auto& kv : ctr) {
        bucket.push_back({kv.second, kv.first});
    }
    auto better = [](const pair<int,int>& A, const pair<int,int>& B){
        if (A.first != B.first) return A.first > B.first;
        return A.second > B.second;
    };
    sort(bucket.begin(), bucket.end(), better);

    long long res = 0;
    int take = min<int>(x, bucket.size());
    for (int i = 0; i < take; ++i) {
        res += 1LL * bucket[i].first * bucket[i].second;
    }
    return res;
}

vector<int> findXSum(const vector<int>& nums, int k, int x) {
    int n = (int)nums.size();
    vector<long long> answer;
    if (k <= 0 || x <= 0 || n == 0 || k > n) return answer;
    unordered_map<int,int> ctr;
    ctr.reserve(k * 2);
    for (int i = 0; i < k; ++i) {
        ++ctr[nums[i]];
    }
    answer.push_back(compute_xsum_from_counts(ctr, x));
    for (int r = k; r < n; ++r) {
        int out = nums[r - k];
        int in  = nums[r];

        auto it = ctr.find(out);
        if (it != ctr.end()) {
            if (--(it->second) == 0) ctr.erase(it);
        }
        ++ctr[in];

        answer.push_back(compute_xsum_from_counts(ctr, x));
    }
    return answer;
}

int main(){
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    int x = 2;
    vector<long long> result = findXSum(nums, k, x);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}