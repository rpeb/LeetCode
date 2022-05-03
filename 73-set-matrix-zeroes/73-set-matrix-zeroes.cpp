class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        queue<pair<int,int>> q;
        int m = matrix.size();
        int n = matrix[0].size();
        // find all the zero positions and insert the indices in a queue
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    q.push({i,j});
                }
            }
        }
        while (!q.empty()) {
            pair<int,int> p = q.front();
            int x = p.first;
            int y = p.second;
            for (int i = 0; i < m; ++i) {
                matrix[i][y] = 0;
            }
            for (int j = 0; j < n; ++j) {
                matrix[x][j] = 0;
            }
            q.pop();
        }
     }
};