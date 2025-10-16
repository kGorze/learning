#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited){
    if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || visited[i][j] || grid[i][j] == 0){
        return 0;
    }
    int area = 1;
    visited[i][j] = true;
    area += dfs(grid, i+1, j, visited);
    area += dfs(grid, i-1, j, visited);
    area += dfs(grid, i, j+1, visited);
    area += dfs(grid, i, j-1, visited);
    return area;
}

int maxAreaOfIsland(vector<vector<int>>& grid){
int max_area = 0;
vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
for(int i = 0; i < grid.size(); i++){
    for(int j = 0; j < grid[0].size(); j++){
        if(grid[i][j] == 1 && !visited[i][j]){
            max_area = max(max_area, dfs(grid, i, j, visited));
        }
    }
}
return max_area;
}

int main(){
    vector<vector<int>> grid = {{0,1,0,0,0}, {1,1,1,0,0}, {0,1,0,0,0}, {0,0,0,0,0}, {0,0,0,0,0}};
    std::cout << maxAreaOfIsland(grid) << std::endl;
    return 0;
}