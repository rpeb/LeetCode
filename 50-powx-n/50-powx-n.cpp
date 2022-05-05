class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long m = n;
        if (n < 0) {
            m = -m;
            x = 1 / x;
        }
        while (m) {
            if (m & 1) {
                ans *= x;
            }
            x *= x;
            m >>= 1;
        }
        return ans;
    }
};