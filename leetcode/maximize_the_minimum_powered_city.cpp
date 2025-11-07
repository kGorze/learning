#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool can_make(const vector<long long>& base, int r, long long k, long long M) {
    int n = (int)base.size();
    vector<long long> add(n, 0);
    long long window = 0;

    auto in_range = [&](int idx){ return 0 <= idx && idx < n; };

    for (int i = 0; i < n; ++i) {
        long long current = base[i] + window;
        if (current < M) {
            long long need = M - current;
            if (need > k) return false;
            k -= need;
            int pos = min(n - 1, i + r);
            add[pos] += need;
            window += need;
        }
        int out_idx = i - r, in_idx = i + r + 1;
        if (in_range(out_idx)) window -= add[out_idx];
        if (in_range(in_idx )) window += add[in_idx];
    }
    return true;
}

long long binsearch_maxM(const vector<long long>& base, int r, long long k) {
    long long min_base = *min_element(base.begin(), base.end());
    long long lo = 0, hi = min_base + k;
    while (lo < hi) {
        long long mid = (lo + hi + 1) / 2;
        if (can_make(base, r, k, mid)) lo = mid; else hi = mid - 1;
    }
    return lo;
}

long long maxPower(vector<int>& stations, int r, int k) {
    int n = (int)stations.size();
    vector<long long> pref(n+1, 0);
    for (int i = 0; i < n; ++i) pref[i+1] = pref[i] + stations[i];

    vector<long long> base(n);
    for (int i = 0; i < n; ++i) {
        int L = max(0, i - r);
        int R = min(n - 1, i + r);
        base[i] = pref[R + 1] - pref[L];
    }
    return binsearch_maxM(base, r, k);
}

int main(){
    vector<int> stations = {1,2,4,5,0};
    int r = 1;
    int k = 2;
    std::cout<<maxPower(stations, r, k)<<std::endl;
    return 0;
}