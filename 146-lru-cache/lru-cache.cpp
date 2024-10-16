class LRUCache {
public:
    LRUCache(int capacity): capacity(capacity) {} 
        
    
    
    int get(int key) {
        // If the key is not found, return -1
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1;
        }
        
        // If the key is found, move the accessed element to the front (most recently used)
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        
        // Return the value of the key
        return cacheMap[key]->second;
    }
    
    void put(int key, int value) {
      // If the key already exists, we update the value and move the key to the front (most recently used)
        if (cacheMap.find(key) != cacheMap.end()) {
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            cacheMap[key]->second = value;  // Update the value
            return;
        }
        
        // If the cache is full, remove the least recently used element (at the back of the list)
        if (cacheList.size() == capacity) {
            int leastUsedKey = cacheList.back().first;
            cacheList.pop_back();
            cacheMap.erase(leastUsedKey);
        }
        
        // Insert the new key-value pair at the front (most recently used position)
        cacheList.emplace_front(key, value);
        cacheMap[key] = cacheList.begin();  
    }
    private:
    // Define the capacity of the LRU cache
    int capacity;
    
    // A list of key-value pairs where the most recently used element is at the front, and the least recently used is at the back
    list<pair<int, int>> cacheList;
    
    // An unordered map for fast access to the list nodes by key
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */