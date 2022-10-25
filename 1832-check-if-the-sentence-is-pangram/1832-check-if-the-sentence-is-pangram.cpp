class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> cs(sentence.begin(), sentence.end());
        for (char c = 'a'; c <= 'z'; ++c) {
            if (cs.find(c) == cs.end()) {
                return false;
            }
        }
        return true;
    }
};