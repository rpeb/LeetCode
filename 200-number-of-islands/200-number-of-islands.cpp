class Solution {
    void bfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        int dirs[] = {0,-1,0,1,0};
        while (!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            grid[x][y] = '0';
            for (int d = 0; d < 4; ++d) {
                int r = x + dirs[d];
                int c = y + dirs[d+1];
                if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
                    q.push({r,c});
                    grid[r][c] = '0';
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