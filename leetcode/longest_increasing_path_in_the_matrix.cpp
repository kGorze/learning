#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dfs(const vector<vector<int>>& matrix, int rows, int cols, vector<vector<int>>& cache){
    if(cache[rows][cols] != 0) return cache[rows][cols];

    int R = static_cast<int>(matrix.size());
    int C = static_cast<int>(matrix[0].size());

    
    int max_path = 1;
    static int directions_row[] = {0, 0, 1, -1};
    static int directions_col[] = {1, -1, 0, 0};

    for(int k = 0; k < 4; k++){
        int new_row = rows + directions_row[k];
        int new_col = cols + directions_col[k];
        if(new_row >= 0 && new_row < R && new_col >= 0 && new_col < C && matrix[new_row][new_col] > matrix[rows][cols]){
            max_path = max(max_path, 1 + dfs(matrix, new_row, new_col, cache));
        }
    }
    cache[rows][cols] = max_path;
    return max_path;
}

int longestIncreasingPath(const vector<vector<int>>& matrix) {
    if(matrix.size() == 0) return 0;
    int rows = matrix.size();
    int cols = matrix[0].size();
    int max_path = 0;
    vector<vector<int>> cache(rows, vector<int>(cols, 0));
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            max_path = max(max_path, dfs(matrix, i, j, cache));
        }
    }
    return max_path;
}

int main(){
    vector<vector<int>> matrix = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
    std::cout << longestIncreasingPath(matrix) << std::endl;
    return 0;
}