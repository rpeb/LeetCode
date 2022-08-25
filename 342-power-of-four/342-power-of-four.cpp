class Solution {
    
public:
    bool isPowerOfFour(int n) {
        if (n == 0) return false;
        double lognBase2 = log2(n);
        cout << "lognBase2 = " << ceil(lognBase2) << "\n";
        int log4Base2 = 2;
        if (ceil(lognBase2) == floor(lognBase2)) {
            return (int)lognBase2 % log4Base2 == 0;
        } else {
            return false;
        }
    }
};