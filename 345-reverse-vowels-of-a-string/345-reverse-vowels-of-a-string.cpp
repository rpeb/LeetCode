class Solution {
    bool isVowel(char c) {
        char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        // cout << "c = " << c << "\n";
        for (int i = 0; i < 10; ++i) {
            if (c == vowels[i]) return true;
        }
        return false;
    }
public:
    string reverseVowels(string s) {
        // cout << "isVowel('a') = " << isVowel('a') << "\nisVowel('b') = " << isVowel('b') << "\nisVowel('u') = " << isVowel('u') << "\n";
        int l = 0, r = s.size() - 1;
        char t;
        bool isVowelLeft = false, isVowelRight = false;
        while (l < r) {
                // cout << "l = " << l << ", r = " << r << "\n";
            // cout << "s = " << s << "\n";
            isVowelLeft = isVowel(s[l]);
            isVowelRight = isVowel(s[r]);
            
            if (isVowelLeft && isVowelRight) {
                t = s[l];
                s[l] = s[r];
                s[r] = t;
                l++;
                r--;
            } else if (isVowelLeft) {
                r--;
            } else if (isVowelRight) {
                l++;
            } else {
                l++;
                r--;
            }
        }
        return s;
    }
};