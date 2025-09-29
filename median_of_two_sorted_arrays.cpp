#include <vector>
#include <iostream>
#include <algorithm>

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    //A is i from 0 to m -1
    //B is j = (m+n+1)/2 - i

    const std::vector<int>*A = &nums1, *B = &nums2;
    if(A->size() > B->size()){
        std::swap(A, B);
    }
    int m = static_cast<int>(A->size());
    int n = static_cast<int>(B->size());
    int total = m + n;
    int left = 0, right = m;
    while(left <= right){
    int i = (left + right) / 2;
    int j = (m + n + 1) / 2 - i;


    int Aleft = i - 1 >= 0 ? (*A)[i - 1] : INT_MIN;
    int Aright = i < m ? (*A)[i] : INT_MAX;
    int Bleft = j - 1 >= 0 ? (*B)[j - 1] : INT_MIN;
    int Bright = j < n ? (*B)[j] : INT_MAX;

    if(Aleft > Bright){
        right = i - 1;
    }
    else if(Bleft > Aright){
        left = i + 1;
    }
    else{
        if(total % 2 == 0){
            return (std::max(Aleft, Bleft) + std::min(Aright, Bright)) / 2.0;
        }
        else{
            return std::max(Aleft, Bleft);
        }
    }
    }
    return 0;
}

int main(){
    std::vector<int> nums1 = {1, 3};
    std::vector<int> nums2 = {2};
    std::cout << findMedianSortedArrays(nums1, nums2) << std::endl;
    return 0;
}