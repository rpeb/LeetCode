class Solution {
    bool isVowel(char c) {
        char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for (int i = 0; i < 10; ++i) {
            if (c == vowels[i]) return true;
        }
        return false;
    }
public:
    string reverseVowels(string s) {
        
        // pointers
        int l = 0, r = s.size() - 1;
        
        // storage vars
        char t;
        bool isVowelLeft = false, isVowelRight = false;
        
        while (l < r) {
                
            isVowelLeft = isVowel(s[l]);
            isVowelRight = isVowel(s[r]);
            
            if (isVowelLeft && isVowelRight) {
                // swap s[l] and s[r]
                t = s[l];
                s[l] = s[r];
                s[r] = t;
                // move the pointers
                l++;
                r--;
            } else if (isVowelLeft) {
                // find a vowel on the right, staying at vowel on left
                r--;
            } else if (isVowelRight) {
                // find a vowel on the left, staying at vowel on right
                l++;
            } else {
                // no vowels on l or r, so move the pointers
                l++;
                r--;
            }
        }
        return s;
    }
};