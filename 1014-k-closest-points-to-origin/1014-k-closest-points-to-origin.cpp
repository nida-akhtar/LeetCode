#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        // Max-heap to store the K closest points by their squared distance
        priority_queue<pair<int, vector<int>>> maxHeap;
        
        // Iterate over all points
        for (const vector<int>& point : points) {
            int x = point[0];
            int y = point[1];
            int dist = x * x + y * y; // Calculate squared distance to avoid floating-point operations
            
            // Push the current point into the heap with its distance
            maxHeap.push({dist, point});
            
            // If the heap size exceeds K, remove the farthest point
            if (maxHeap.size() > K) {
                maxHeap.pop();
            }
        }
        
        // Extract the K closest points from the heap
        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        
        return result;
    }
};
