class Solution {
public:
    bool checkValidString(string s) {
        int lo = 0, hi = 0;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            
            if (c == '(') {
                lo++;
                hi++;
            } else if (c == ')') {
                if (lo > 0) lo--;
                hi--;
            } else {
                if (lo > 0) lo--;
                hi++;
            }
            
            // 1. if number of ) is more than number of * and (, hi becomes negative
            // 2. ) can only be balanced by * or ( in front of it
            //    so even if we have more *, ( later on and hi becomes positive,
            //    we already have an invalid substring that cannot be made valid
            //
            // 3. *(*))),(*)) : the substring before comma is already invalid and hi < 0                                     there, since it makes whole string invalid we return false
            
            
            if (hi < 0) {
                return false;
            }
        }
        
        
        return lo == 0;
    }
};