#include <vector>
#include <iostream>
using namespace std;

int minNumberOperations(vector<int>& target) {
//increment the entire range by the minimum value. the minumum value can be obtained with range minimum query or segment tress algorithm
int ans = 0;
int prev = 0;
for(int i = 0; i < target.size(); ++i){
ans += max(0, target[i] - prev);
prev = target[i];
}
return ans;
}

int main(){
    vector<int> target = {3,1,5,4,2};
    cout << minNumberOperations(target) << endl;
    return 0;
}