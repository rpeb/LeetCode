class MyHashMap {
    vector<list<pair<int,int>>> map;
    int size;
    
    int hash(int key) {
        return key % size;
    }
    
    auto search(int key) {
        int i = hash(key);
        for (auto it = map[i].begin(); it != map[i].end(); ++it) {
            if (it->first == key) {
                return it;
            }
        }
        return map[i].end();
    }
    
public:
    MyHashMap() {
        size = 10;
        map.resize(size);
    }
    
    void put(int key, int value) {
        remove(key);
        int i = hash(key);
        auto it = search(key);
        if (it == map[i].end()) {
            map[i].push_back({key,value});
        }
    }
    
    int get(int key) {
        int i = hash(key);
        for (auto it = map[i].begin(); it != map[i].end(); ++it) {
            if (it->first == key) {
                return it->second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int i = hash(key);
        auto it = search(key);
        if (it != map[i].end()) {
            map[i].erase(it);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */