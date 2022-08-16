class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = m;
        vector<vector<int>> res(m-2, vector<int>(n-2));
        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                int mx = 0;
                for (int r = i-1; r <= i + 1; ++r) {
                    for (int c = j-1; c <= j + 1; ++c) {
                        mx = max(mx, grid[r][c]);
                    }
                }
                res[i-1][j-1] = mx;
            }
        }
        return res;
    }
};