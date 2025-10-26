#include <vector>
#include <iostream>
#include <climits>
using namespace std;

int maximalRectangle(vector<vector<char>>& matrix){
// the idea is to create an dp algorithm that would do the subproblem
int n = matrix.size();
int m = matrix[0].size();

vector<vector<int>> width(n, vector<int>(m,0));

for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
        if(matrix[i][j] == '1'){
            width[i][j] = (j > 0 ? width[i][j-1]: 0) + 1;
        }
        else{
            width[i][j] = 0;
        }
    }
}

int max_area = 0;
for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
        if(width[i][j] == 0) continue;
        int min_width = INT_MAX;
        for(int k = i; k >= 0 && width[k][j] > 0; --k){
            min_width = min(min_width, width[k][j]);
            int area = (i - k + 1) * min_width;
            max_area = max(max_area, area);
        }
    }
}
return max_area;
}

int main(){
    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    std::cout << maximalRectangle(matrix) << std::endl;
    return 0;
}