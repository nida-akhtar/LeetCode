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
        
        // If the key is found, move the accessed element to the front (most recently used)
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        
        // Return the value of the key
        return cacheMap[key]->second;
    }
    
    // Put the key-value pair in the cache. If the number of keys exceeds the capacity, evict the least recently used key.
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
