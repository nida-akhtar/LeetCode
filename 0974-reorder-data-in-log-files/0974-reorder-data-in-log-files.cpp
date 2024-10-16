#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        // Custom comparator for sorting letter-logs in-place
        auto compare = [](const string& log1, const string& log2) {
            // Find the first space to separate identifier from content
            int pos1 = log1.find(' ');
            int pos2 = log2.find(' ');
            
            // Instead of substr(), directly compare the contents by using indices
            const string& content1 = log1.substr(pos1 + 1);
            const string& content2 = log2.substr(pos2 + 1);
            
            // If contents are the same, compare by identifier
            if (content1 == content2) {
                return log1.substr(0, pos1) < log2.substr(0, pos2);
            }
            // Otherwise, compare lexicographically by content
            return content1 < content2;
        };
        
        // Use stable partition to move digit-logs to the end
        auto it = stable_partition(logs.begin(), logs.end(), [](const string& log) {
            int pos = log.find(' ');
            return isalpha(log[pos + 1]);  // Check if it's a letter-log
        });
        
        // Sort only the letter-logs (the partitioned range)
        sort(logs.begin(), it, compare);

        return logs;
    }
};
