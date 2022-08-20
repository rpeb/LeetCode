class Solution {
    void bfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        int row[] = {-1,0,1,0};
        int col[] = {0,1,0,-1};
        while (!q.empty()) {
            auto f = q.front(); q.pop();
            int x = f.first;
            int y = f.second;
            grid[x][y] = '0';
            for (int p = 0; p < 4; ++p) {
                int r = x+row[p];
                int c = y+col[p];
                if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
                    grid[r][c] = '0';
                    q.push({r,c});
                }
                    
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    bfs(grid,i,j);
                    res++;
                }
            }
        }
        return res;
    }
};