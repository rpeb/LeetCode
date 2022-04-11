class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        // flatten the grid in a vector<int>
        vector<int> flatGrid;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                flatGrid.push_back(grid[i][j]);
            }
        }
        
        
        // shifting in the flat grid - start
        for (int i = 0; i < k; ++i)
            flatGrid.push_back(0);
        
        for (int i = m * n - 1; i >= 0; --i) {
            flatGrid[i+k] = flatGrid[i];
        }
        
        for (int i = 0; i < m * n + k; ++i) {
            flatGrid[i % (m * n)] = flatGrid[i];
        }
        
        while (k--) {
            flatGrid.pop_back();
        }
        // shifting in the flatten grid - end
        
        
        // forming resulting 2-D vector from flat grid
        vector<vector<int>> res(m, vector<int>(n));
        int l = 0;
        for (int i = 0; i < m; ++i) {
            vector<int> row(n);
            for (int j = 0; j < n; ++j) {
                 res[i][j] = flatGrid[l++];
            }
        }
        return res;
    }
};