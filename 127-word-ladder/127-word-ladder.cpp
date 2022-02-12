class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordListSet(wordList.begin(), wordList.end());
        int n = beginWord.size();
        queue<string> bfsQueue;
        bfsQueue.push(beginWord);
        int depth = 0, lsize = 0;
        while (!bfsQueue.empty()) {
            lsize = bfsQueue.size();
            while (lsize--) {
                string word = bfsQueue.front();
                if (word == endWord) {
                    return depth + 1;
                }
                bfsQueue.pop();
                for (int i = 0; i < n; ++i) {
                    string tmp = word;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        tmp[i] = c;
                        if (wordListSet.find(tmp) != wordListSet.end()) {
                            bfsQueue.push(tmp);
                            wordListSet.erase(tmp);
                        }
                    }
                }
            }
            depth++;
        }
        return 0;
    }
};