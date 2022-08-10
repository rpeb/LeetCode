class LRUCache {
// private:
//     unordered_map<int, list<int>::iterator> iteratormap;
//     unordered_map<int, int> cache;
//     list<int> lru;
//     int capacity;
    
//     void updateUsage(int key) {
//         // shift the key to front of list
//         // if key present in iteratormap
//         // change value of iteratormap[key] to lru.begin()
//         if (iteratormap.find(key) != iteratormap.end()) {
//             lru.erase(iteratormap[key]);
//         } else if (lru.size() >= capacity) {
//             int old = lru.back();
//             lru.pop_back();
//             iteratormap.erase(old);
//             cache.erase(old);
//         }
//         lru.push_front(key);
//         iteratormap[key] = lru.begin();
//     }
public:
//     LRUCache(int capacity) {
//         this->capacity = capacity;
//     }
    
//     int get(int key) {
//         if (iteratormap.find(key) != iteratormap.end()) {
//             updateUsage(key);
//             return cache[key];
//         }
//         return -1;
//     }
    
//     void put(int key, int value) {
//         updateUsage(key);
//         cache[key] = value;
//     }
    public:
    LRUCache(int capacity) : _capacity(capacity) {}
    
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;
        touch(it);
        return it->second.first;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) touch(it);
        else {
			if (cache.size() == _capacity) {
				cache.erase(used.back());
				used.pop_back();
			}
            used.push_front(key);
        }
        cache[key] = { value, used.begin() };
    }
    
private:
    typedef list<int> LI;
    typedef pair<int, LI::iterator> PII;
    typedef unordered_map<int, PII> HIPII;
    
    void touch(HIPII::iterator it) {
        int key = it->first;
        used.erase(it->second.second);
        used.push_front(key);
        it->second.second = used.begin();
    }
    
    HIPII cache;
    LI used;
    int _capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */