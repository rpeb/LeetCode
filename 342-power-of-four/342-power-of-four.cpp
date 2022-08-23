class Solution {
    // int base;
public:
    bool isPowerOfFour(int n) {
        while (n > 1) {
            // cout << "n = " << n << "\n";
            if (n % 4) return false;
            n /= 4;
        }
        return n == 1;
    }
};