#include <vector>
#include <iostream>
using namespace std;

void dfsMark(std::vector<std::vector<char>>& b, int i, int j, int n, int m) {
    if (i < 0 || i >= n || j < 0 || j >= m || b[i][j] != 'O') return;
    b[i][j] = 'T';
    dfsMark(b, i+1, j,   n, m);
    dfsMark(b, i-1, j,   n, m);
    dfsMark(b, i,   j+1, n, m);
    dfsMark(b, i,   j-1, n, m);
}

void solve(vector<vector<char>>& board){
// the main idea would be to use the dfs to findout the regions that are isolated from edges and surrounded with 'X'
int n = board.size();
int m = board[0].size();
for (int i = 0; i < n; ++i) {
    dfsMark(board, i, 0,   n, m);
    dfsMark(board, i, m-1, n, m);
}
for (int j = 0; j < m; ++j) {
    dfsMark(board, 0,   j, n, m);
    dfsMark(board, n-1, j, n, m);
}
for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
        if (board[i][j] == 'O') {
            board[i][j] = 'X';
        }
    }
}
for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
        if (board[i][j] == 'T') {
            board[i][j] = 'O';
        }
    }
}
}

int main(){

    vector<vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    solve(board);
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}