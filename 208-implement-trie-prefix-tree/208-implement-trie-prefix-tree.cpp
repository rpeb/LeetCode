struct TrieNode {
    vector<TrieNode*> children;
    bool endOfWord;
    TrieNode() {
        endOfWord = false;
        children.assign(26, nullptr);
    }
};

class Trie {
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        int idx;
        for (char c: word) {
            idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        int idx;
        for (char c: word) {
            idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                return false;
            }
            curr = curr->children[idx];
        }
        return curr->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        int idx;
        for (char c: prefix) {
            idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                return false;
            }
            curr = curr->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */