class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        // Custom comparator for sorting the letter-logs
        auto compare = [](const string& log1, const string& log2) {
            // Find the first space to separate identifier from content
            int pos1 = log1.find(' ');
            int pos2 = log2.find(' ');
            
            // Extract the identifiers and contents
            string id1 = log1.substr(0, pos1);
            string id2 = log2.substr(0, pos2);
            string content1 = log1.substr(pos1 + 1);
            string content2 = log2.substr(pos2 + 1);
            
            // Compare contents of the logs
            if (content1 == content2) {
                // If contents are the same, compare by identifier
                return id1 < id2;
            }
            // Otherwise, compare lexicographically by content
            return content1 < content2;
        };
        
        // Separate letter-logs and digit-logs
        vector<string> letterLogs, digitLogs;
        
        for (const string& log : logs) {
            // Find the first space after the identifier
            int pos = log.find(' ');
            
            // Check if it's a digit-log or letter-log by looking at the first character after the space
            if (isdigit(log[pos + 1])) {
                // It's a digit-log
                digitLogs.push_back(log);
            } else {
                // It's a letter-log
                letterLogs.push_back(log);
            }
        }
        
        // Sort letter-logs using the custom comparator
        sort(letterLogs.begin(), letterLogs.end(), compare);
        
        // Combine the sorted letter-logs and original digit-logs
        letterLogs.insert(letterLogs.end(), digitLogs.begin(), digitLogs.end());
        
        return letterLogs;
    }
};
