class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int l = 0, r = n-1;
        while (l < r) {
            char t = s[l];
            s[l] = s[r];
            s[r] = t;
            l++;
            r--;
        }
    }
};