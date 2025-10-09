#include <vector>
#include <iostream>
using namespace std;


void dfs(vector<vector<int>>& image, int sr, int sc, int color, int original_color){
    if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != original_color) return;
    image[sr][sc] = color;
    dfs(image, sr + 1, sc, color, original_color);
    dfs(image, sr - 1, sc, color, original_color);
    dfs(image, sr, sc + 1, color, original_color);
    dfs(image, sr, sc - 1, color, original_color);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int original_color = image[sr][sc];
    if(original_color != color) dfs(image, sr, sc, color, original_color);
    return image;
}
        

int main(){
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1;
    int sc = 1;
    int color = 2;
    vector<vector<int>> result = floodFill(image, sr, sc, color);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            std::cout << result[i][j] << " ";
        }
    }
    return 0;
}