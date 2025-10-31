#include <vector>
#include <iostream>
using namespace std;

vector<int> getSneakyNumbers(vector<int>& nums) {
int n = nums.size() - 2;
vector<int> result;
for (size_t i = 0; i < nums.size(); ++i) {
    nums[nums[i] % n] += n;
}

for(int i = 0; i < n; ++i){
    if((nums[i] / n) == 2) result.push_back(i);
}
return result;
}

int main(){
    vector<int> nums = {0,3,1,2,3,0};
    vector<int> result = getSneakyNumbers(nums);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}