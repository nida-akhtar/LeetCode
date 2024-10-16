#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        // Sort the points based on their Euclidean distance from the origin
        sort(points.begin(), points.end(), [](const vector<int>& p1, const vector<int>& p2) {
            int dist1 = p1[0] * p1[0] + p1[1] * p1[1];  // Squared distance of point 1
            int dist2 = p2[0] * p2[0] + p2[1] * p2[1];  // Squared distance of point 2
            return dist1 < dist2;  // Sort by increasing distance
        });
        
        // Return the first K points (closest points)
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};
