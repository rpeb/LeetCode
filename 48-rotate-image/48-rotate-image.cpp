class Solution {
    void print(vector<vector<int>>& matrix) {
        int m = matrix.size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // print(matrix);
        for (int j = 0; j < m; ++j) {
             reverse(matrix[j].begin(), matrix[j].end());
        }
    }
};