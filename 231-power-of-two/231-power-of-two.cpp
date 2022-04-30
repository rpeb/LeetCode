class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 0)
            return false;
        int bits = 0;
        while (n) {
            if (n & 1) bits++;
            n >>= 1;
        }
        return bits == 1;
    }
};