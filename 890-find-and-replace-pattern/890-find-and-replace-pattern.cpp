class Solution {
    string getPatternString(string pattern) {
        unordered_map<char,int> m;
        string patternToInteger;
        int cnt = 0;
        for (char c: pattern) {
            if (m.find(c) == m.end()) {
                m[c] = cnt++;
                patternToInteger += to_string(m[c]);
            }
            else {
                patternToInteger += to_string(m[c]);
            }
        }
        // cout << "patternToInteger = " << patternToInteger << "\n";
        return patternToInteger;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        string intCodeForPattern = getPatternString(pattern);
        for (string word: words) {
            string intCodeForWord = getPatternString(word);
            if (intCodeForPattern == intCodeForWord) {
                res.push_back(word);
            }
        }
        return res;
    }
};