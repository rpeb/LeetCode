class Solution {
    
public:
    string breakPalindrome(string p) {
        int n = p.size();
        int i = 0, j = n - 1;
        while (i < j) {
            if (p[i] != 'a') {
                p[i] = 'a';
                return p;
            }
            i++;
            j--;
        }
        p[n - 1] = 'b';
        return n < 2 ? "" : p;
    }
};