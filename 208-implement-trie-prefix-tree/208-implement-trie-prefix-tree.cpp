struct Node {
    vector<Node*> next;
    bool isWord;
    Node() {
        next.assign(26, nullptr);
        isWord = false;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
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
        Node* curr = root;
        for (char c: word) {
            if (curr->next[c - 'a'] == nullptr) {
                return false;
            }
            curr = curr->next[c - 'a'];
        }
        return curr->isWord;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for (char c: prefix) {
            if (curr->next[c - 'a'] == nullptr) {
                return false;
            }
            curr = curr->next[c - 'a'];
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