#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int numberOfSubstrings(string s) {
    int n = s.size();
    vector<int> zeroPos;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            zeroPos.push_back(i);
        }
    }

    int B = std::sqrt(n);
    long long ans = 0;

    for (int i = 0; i < n; ++i) {
        auto it = std::lower_bound(zeroPos.begin(), zeroPos.end(), i);
        int idx = it - zeroPos.begin();
        if (idx == zeroPos.size()) {
            ans += n - i;
            continue;
        } else {
            int firstZero = zeroPos[idx];
            if (firstZero > i) {
                ans += (firstZero - i);
            }
        }
        for (int z = 1; z <= B; ++z) {
            int needIndex = idx + z - 1;
            if (needIndex >= zeroPos.size()) {
                break;
            }
            int lastZero = zeroPos[needIndex];
            int rHigh;
            int nextIndex = needIndex + 1;
            if (nextIndex < (int)zeroPos.size()) {
                rHigh = zeroPos[nextIndex] - 1;
            } else {
                rHigh = n - 1;
            }
            int rLow1 = lastZero;
            int rLow2 = i + z * z + z - 1;
            int rLow = max(rLow1, rLow2);

            if (rLow > rHigh) {
                continue;
            }
            ans += rHigh - rLow + 1;
        }
    }

    return (int)ans;
}

int main(){
    string s = "101101";
    cout << numberOfSubstrings(s) << endl;
    return 0;
}
