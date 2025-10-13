#include <vector>
#include <iostream>

using namespace std;

vector<long long> find_prefix_sums(vector<int>& nums){
    vector<long long> prefix_sums(nums.size() + 1, 0);
    for(int i = 0; i < nums.size(); i++){
        prefix_sums[i+1] = prefix_sums[i] + static_cast<long long>(nums[i]);
    }
    return prefix_sums;
}


long long count_and_sort(vector<long long>& pref,vector<long long>& temp, int left, int right, int lower, int upper){
    if(right - left <= 1) return 0;
    int mid = left + (right - left)/ 2;

    //answer from the right and left sides
    long long count = 0;
    count += count_and_sort(pref, temp, left, mid, lower, upper);
    count += count_and_sort(pref, temp, mid, right, lower, upper);

    //need to find the number of the pair of indexes in between the sides
    int L = left;
    int R_left = mid;
    int R_right = mid;
    for(; L < mid; ++L){
        long long x = pref[L];
        long long minY = x + lower;
        long long maxY = x + upper;
        while(R_left < right && pref[R_left] < minY){
            R_left++;
        }
        while(R_right < right && pref[R_right] <= maxY){
            R_right++;
        }
        count += R_right - R_left;
    }

    //merge the two sides
    int i = left;
    int j = mid;
    int k = left;
    while(i < mid && j < right){
        if(pref[i] < pref[j]){
            temp[k++] = pref[i++];
        }
        else{
            temp[k++] = pref[j++];
        }
    }
    while(i < mid){
        temp[k++] = pref[i++];
    }
    while(j < right){
        temp[k++] = pref[j++];
    }
    for(int p = left; p < right; p++){
        pref[p] = temp[p];
    }
    return count;
}


int countRangeSum(vector<int>& nums, int lower, int upper) {
        //its a difference of prefix sums. 
        //find the number of the pair of indexes that satisfy that the pref[j] - pref[i] in [lower, upper], where i < j


        //the brute force solution is O(n^2) time and O(n) space, which is not efficient. we need to do that in O(nlogn) time, which is merge sort.
        vector<long long> pref = find_prefix_sums(nums);
        vector<long long> temp(pref.size());

        int count = 0;
        count = count_and_sort(pref, temp, 0, pref.size(), lower, upper);
        return count;
}

int main(){
    vector<int> nums = {-2, 5, -1};
    int lower = -2;
    int upper = 2;
    std::cout << countRangeSum(nums, lower, upper) << std::endl;
    return 0;
}