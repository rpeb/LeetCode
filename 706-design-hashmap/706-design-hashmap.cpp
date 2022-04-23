class MyHashMap {
    vector<int> map;
public:
    MyHashMap() {
        map.assign(1,-1);
    }
    
    void put(int key, int value) {
        int size = map.size() - 1;
        if (key > size) {
            map.resize(key + 1, -1);
        }
        map[key] = value;
    }
    
    int get(int key) {
        int size = map.size() - 1;
        if (key > size) {
            return -1;
        }
        return map[key];
    }
    
    void remove(int key) {
        int size = map.size() - 1;
        if (key <= size) {
            map[key] = -1;
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