class LRUCache {
private:
    unordered_map<int, list<int>::iterator> iteratormap;
    unordered_map<int, int> cache;
    list<int> lru;
    int capacity;
    
    void updateUsage(int key) {
        // shift the key to front of list
        // if key present in iteratormap
        // change value of iteratormap[key] to lru.begin()
        if (iteratormap.find(key) != iteratormap.end()) {
            lru.erase(iteratormap[key]);
        } else if (lru.size() >= capacity) {
            int old = lru.back();
            lru.pop_back();
            iteratormap.erase(old);
            cache.erase(old);
        }
        lru.push_front(key);
        iteratormap[key] = lru.begin();
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (iteratormap.find(key) != iteratormap.end()) {
            updateUsage(key);
            return cache[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        updateUsage(key);
        cache[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */