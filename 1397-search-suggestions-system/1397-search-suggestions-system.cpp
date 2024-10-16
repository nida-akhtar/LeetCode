#include <vector>
#include <string>
#include <algorithm>  // For sort and lower_bound
using namespace std;

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        // Sort the products lexicographically
        sort(products.begin(), products.end());

        vector<vector<string>> result;
        string prefix = "";  // The current prefix we're searching for
        
        // Iterate through each character in the search word
        for (char c : searchWord) {
            prefix += c;  // Build the prefix step by step
            
            // Use lower_bound to find the first product that starts with the current prefix
            auto it = lower_bound(products.begin(), products.end(), prefix);
            
            // Prepare a vector to store the top 3 suggestions for the current prefix
            vector<string> suggestions;
            
            // Iterate through the next 3 products in the sorted list, checking if they match the prefix
            for (int i = 0; i < 3 && it + i != products.end(); ++i) {
                string& product = *(it + i);
                if (product.find(prefix) == 0) {  // Check if the product starts with the prefix
                    suggestions.push_back(product);
                } else {
                    break;  // If the product doesn't match, stop early
                }
            }
            
            // Add the suggestions for this prefix to the result
            result.push_back(suggestions);
        }
        
        return result;
    }
};
