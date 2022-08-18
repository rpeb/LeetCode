class Solution {
    string morse(string word) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        // int n = word.size();
        string res;
        for (char c: word) {
            int offset = c - 'a';
            res += morse[offset];
        }
        return res;
    }
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> transformations;
        for (string word: words) {
            transformations.insert(morse(word));
        }
        return transformations.size();
    }
};