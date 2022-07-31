class Solution {
    void printVector(vector<vector<int>>& v) {
        for (vector<int> vint: v) {
            for (int i: vint) {
                cout << i << " ";
            }
            cout << "\n";
        }
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<vector<int>> patternVector(26);
        int patternLength = pattern.size();
        int offset;
        for (int i = 0; i < patternLength; ++i) {
            offset = pattern[i] - 'a';
            patternVector[offset].push_back(i);
        }
        sort(patternVector.begin(), patternVector.end());
        vector<string> res;
        for (string word: words) {
            vector<vector<int>> matchVector(26);
            int wordLength = word.size();
            for (int i = 0; i < wordLength; ++i) {
                offset = word[i] - 'a';
                matchVector[offset].push_back(i);
            }
            sort(matchVector.begin(), matchVector.end());
            if (patternVector == matchVector) {
                res.push_back(word);
            }
        }
        return res;
    }
};