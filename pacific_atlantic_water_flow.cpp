#include <vector>
#include <iostream>

using namespace std;



void dfs(const vector<vector<int>>& h, vector<vector<bool>>& vis, int r, int c) {
    static const int DR[4] = {1,-1,0,0};
    static const int DC[4] = {0,0,1,-1};
    if (vis[r][c]) return;
    vis[r][c] = true;

    int m = (int)h.size(), n = (int)h[0].size();
    for (int k = 0; k < 4; ++k) {
        int nr = r + DR[k], nc = c + DC[k];
        if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
        if (!vis[nr][nc] && h[nr][nc] >= h[r][c]) {
            dfs(h, vis, nr, nc);
        }
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int m = (int)heights.size();
    int n = (int)heights[0].size();
    

    vector<vector<bool>> pac(m, vector<bool>(n,false));
    vector<vector<bool>> atl(m, vector<bool>(n,false));

    for (int r = 0; r < m; ++r) {
        dfs(heights, pac, r, 0);
        dfs(heights, atl, r, n-1);
    }
    for (int c = 0; c < n; ++c) {
        dfs(heights, pac, 0, c);
        dfs(heights, atl, m-1, c);
    }

    vector<vector<int>> ans;
    for (int r = 0; r < m; ++r)
        for (int c = 0; c < n; ++c)
            if (pac[r][c] && atl[r][c]) ans.push_back({r,c});
    return ans;
}
