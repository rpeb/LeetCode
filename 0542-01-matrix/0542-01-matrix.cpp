class Solution {
    
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    q.push({i,j});
                    visited[i][j] = 1;
                }
            }
        }
        int dist = 0;
        int dirs[] = {-1,0,1,0,-1};
        while (!q.empty()) {
            dist++;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto front = q.front();
                q.pop();
                int f = front.first;
                int s = front.second;
                // cout << "f = " << f << ", s = " << s << "\n";
                for (int d = 0; d < 4; ++d) {
                    int x = f + dirs[d];
                    int y = s + dirs[d+1];
                    if (min(x,y) >= 0 && x < m && y < n && visited[x][y] == 0) {
                        // cout << "m = " << m << ", n = " << n << "\n";
                        q.push({x,y});
                        visited[x][y] = 1;
                        mat[x][y] = dist;
                    }
                }
            }
        }
        return mat;
    }
};