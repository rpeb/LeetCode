class Solution {
    int findMaxSurround(vector<vector<int>>& grid,int x,int y) {
        int row[] = {-1,-1,-1,0,0,0,1,1,1};
        int col[] = {-1,0,1,-1,0,1,-1,0,1};
        int mx = grid[x][y];
        for (int i = 0; i < 9; ++i) {
            mx = max(mx,grid[x + row[i]][y + col[i]]);
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
                row[j-1] = findMaxSurround(grid,i,j);
            }
            res.push_back(row);
        }
        return res;
    }
};