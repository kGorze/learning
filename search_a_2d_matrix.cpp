#include <vector>
#include <iostream>

bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
std::vector<int> flat_matrix; 
for(int i = 0; i < matrix.size(); i++){
    flat_matrix.insert(flat_matrix.end(), matrix[i].begin(), matrix[i].end());
}
int left = 0;
int right = flat_matrix.size() - 1;
while(left <= right){
    int mid = left + (right - left)/2;
    if(flat_matrix[mid] == target){
        return true;
    }
    else if(flat_matrix[mid] < target){
        left = mid + 1;
    }
    else{
        right = mid - 1;
    }
}
return false;
}

bool searchMatrix1(std::vector<std::vector<int>>& matrix, int target) {
    int row = 0;
    for(int i = 0; i < matrix.size(); i++){
        if(matrix[i][0] <= target && matrix[i][matrix[i].size() - 1] >= target){
            row = i;
            break;
        }
    }
    int left = 0;
    int right = matrix[row].size() - 1;
    while(left <= right){
        int mid = left + (right - left)/2;
        if(matrix[row][mid] == target){
            return true;
        }
        else if(matrix[row][mid] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return false;
}
int main(){
    std::vector<std::vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;
    std::cout << searchMatrix(matrix, target) << std::endl;
    return 0;
}