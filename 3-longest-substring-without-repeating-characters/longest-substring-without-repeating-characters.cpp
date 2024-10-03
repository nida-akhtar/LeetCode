class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        vector<int> lastIndex(128, 0);  // Record last index of each character
        
        for (int start = 0, end = 0; end < n; end++) {
            char currentChar = s[end];
            int& lastPos = lastIndex[currentChar]; // Store reference to reduce lookup cost
            start = max(start, lastPos);
            maxLength = max(maxLength, end - start + 1);
            lastPos = end + 1;
        }
        
        return maxLength;
    }
};
