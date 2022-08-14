struct TrieNode {
    vector<TrieNode*> next;
    bool endOfWord;
    TrieNode() {
        next.assign(26, nullptr);
        endOfWord = false;
    }
};

class WordDictionary {
    TrieNode *root;
    bool searchHelper(TrieNode* root, int idx, string word) {
        int n = word.size();
        if (root && idx == n) return root->endOfWord;
        if (!root) return false;
        TrieNode* curr = root;
        int offset;
        bool flag = false;
        for (int i = idx; i < n; ++i) {
            char c = word[i];
            offset = c - 'a';
            if (c != '.') {
                if (curr->next[offset] == nullptr) {
                    return false;
                }
                curr = curr->next[offset];
            } else {
                for (int j = 0; j < 26; ++j) {
                    if (curr->next[j]) {
                        flag = searchHelper(curr->next[j], i + 1, word);
                    }
                    if (flag) {
                        return true;
                    }
                }
                return false;
            }
        }
        return curr->endOfWord;
    }
    
    bool searchHelper1(string word, int idx, TrieNode* root) {
        if (root and idx == word.size())
            return root->endOfWord;
        
        if (!root)
            return false;
        int n = word.size();
        TrieNode* curr = root;
        bool temp = false;
        for (int i = idx; i < n; ++i) {
            if (word[i] != '.') {
                if (!curr->next[word[i] - 'a'])
                    return false;
                curr = curr->next[word[i]-'a'];
            } else {
                for (int j = 0; j < 26; ++j) {
                    if (curr->next[j]) {
                        temp = searchHelper1(word, i+1, curr->next[j]);
                    }
                    if (temp)
                        return true;
                }
                return false;
            }
        }
        return curr->endOfWord;
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        int idx;
        for (char c: word) {
            idx = c - 'a';
            if (curr->next[idx] == nullptr) {
                curr->next[idx] = new TrieNode();
            }
            curr = curr->next[idx];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        // return searchHelper(root, 0, word);
        return searchHelper1(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */