class Solution {
    void printVec(vector<int>& freq) {
        for (int i = 0; i < 26; ++i) {
            cout << "i = " << (char)(i+97) << ", freq[i] = " << freq[i] << "\n";
        }
    }
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int n1 = s.size(), n2 = t.size();
        vector<int> m(26, 0);
        for (int i = 0; i < n1; ++i) {
            m[s[i]-'a']++;
        }
        for (int i = 0; i < n2; ++i) {
            if (m[t[i]-'a'] > 0) {
                m[t[i]-'a']--;
            }
            else
                return false;
        }
        for (int i = 0; i < 26; ++i) {
            if (m[i] != 0)
                return false;
        }
        return true;
    }
};