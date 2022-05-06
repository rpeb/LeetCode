class Solution {
    int a[101][101] = {0};
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1)
            return 1;
        if (a[m-1][n] == 0) {
            a[m-1][n] = uniquePaths(m-1, n);
        }
        if (a[m][n-1] == 0) {
            a[m][n-1] = uniquePaths(m, n-1);
        }
        return a[m][n-1] + a[m-1][n];
    }
};