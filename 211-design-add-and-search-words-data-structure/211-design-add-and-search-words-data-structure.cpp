struct Node {
    vector<Node*> next;
    bool isWord;
    Node() {
        next.assign(26, nullptr);
        isWord = false;
    }
};
class WordDictionary {
    Node* root;
    bool searchHelper(Node* root, int idx, string word) {
        if (!root) return false;
        if (idx == word.size()) return root->isWord;
        int n = word.size();
        Node* curr = root;
        char c;
        int offset;
        for (int i = idx; i < n; ++i) {
            c = word[i];
            offset = c - 'a';
            if (c == '.') {
                for (auto node: curr->next) {
                    if (node) {
                        if (searchHelper(node, i + 1, word)) {
                            return true;
                        }
                    }
                }
                return false;
            }
            if (curr->next[offset] == nullptr) {
                return false;
            }
            curr = curr->next[offset];
        }
        return curr->isWord;
    }
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;
        for (char c: word) {
            if (curr->next[c - 'a'] == nullptr) {
                curr->next[c - 'a'] = new Node();
            }
            curr = curr->next[c - 'a'];
        }
        curr->isWord = true;
    }
    
    bool search(string word) {
        return searchHelper(root, 0, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */