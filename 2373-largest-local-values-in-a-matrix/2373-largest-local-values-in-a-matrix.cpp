class Solution {
    int findMaxSurround(vector<vector<int>>& grid,int x,int y) {
        int col[] = {-1,0,1,-1,0,1,-1,0,1};
        int row[] = {-1,-1,-1,0,0,0,1,1,1};
        int mx = grid[x][y];
        for (int i = 0; i < 9; ++i) {
            int r = x + row[i];
            int c = y + col[i];
            // if (x == 1 && y == 1)
            //     cout << "r = " << r << ", c = " << c << "\n";
            mx = max(mx,grid[r][c]);
        }
        return mx;
    }
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = m;
        vector<vector<int>> res;
        for (int i = 1; i < m - 1; ++i) {
            vector<int> row(m-2);
            for (int j = 1; j < n - 1; ++j) {
                // cout << "i = " << i << ", j = " << j << "\n";
                row[j-1] = findMaxSurround(grid,i,j);
            }
            res.push_back(row);
        }
        return res;
    }
};