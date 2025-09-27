//should aim for the O(n) time and O(n) space
#include <vector>
#include <iostream>


int largestRectangleArea(std::vector<int>& heights) {
    // we should precompute the left and the right bounds for each index, but how do we do that?
    //this would speed up the process and not making it the O(n^2) time complexity
    int n = (int)heights.size();
    std::vector<int> left_bounds(n, -1);
    std::vector<int> right_bounds(n,n);

    for (int i = 0; i < n; ++i) {
        int j = i - 1;
        while (j >= 0 && heights[j] >= heights[i]) {
            j = left_bounds[j]; 
        }
        left_bounds[i] = j;
    }

    for(int i = n - 1; i >= 0; --i){
        int j = i + 1;
        while(j < n && heights[j] >= heights[i]){
            j = right_bounds[j];
        }
        right_bounds[i] = j;
    }

    int max_area = 0;
    for (int i = 0; i < n; ++i) {
        int width = right_bounds[i] - left_bounds[i] - 1;
        int area  = heights[i] * width;
        if (area > max_area) max_area = area;
    }
    return max_area;

}
int main(){
    std::vector<int> heights = {2, 1, 5, 6, 2, 3};
    std::cout << largestRectangleArea(heights) << std::endl;
    return 0;
}