#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    // Get the value of the key if the key exists in the cache, otherwise return -1.
    int get(int key) {
        // If the key is not found, return -1
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1;
        }
        
        // Move the accessed key-value pair to the front (most recently used)
        moveToFront(key);
        
        // Return the value associated with the key
        return cacheMap[key]->second;
    }
    
    // Put the key-value pair in the cache. If the number of keys exceeds the capacity, evict the least recently used key.
    void put(int key, int value) {
        // If the key already exists, update the value and move it to the front
        if (cacheMap.find(key) != cacheMap.end()) {
            moveToFront(key);
            cacheMap[key]->second = value;  // Update the value
            return;
        }
        
        // If the cache is full, remove the least recently used element (from the back)
        if (cacheList.size() == capacity) {
            evictLRU();
        }
        
        // Insert the new key-value pair at the front (most recently used position)
        cacheList.emplace_front(key, value);
        cacheMap[key] = cacheList.begin();
    }

private:
    // Cache capacity
    int capacity;
    
    // List of key-value pairs, where the front is the most recently used and the back is the least recently used
    list<pair<int, int>> cacheList;
    
    // Unordered map for fast access to list nodes by key
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;

    // Move the given key to the front of the list (most recently used)
    void moveToFront(int key) {
        // If the key is already at the front, no need to move it
        if (cacheMap[key] != cacheList.begin()) {
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        }
    }
    
    // Evict the least recently used element from the cache
    void evictLRU() {
        // Get the key of the least recently used element (back of the list)
        int leastUsedKey = cacheList.back().first;
        cacheList.pop_back();             // Remove the element from the list
        cacheMap.erase(leastUsedKey);     // Erase it from the map
    }
};
