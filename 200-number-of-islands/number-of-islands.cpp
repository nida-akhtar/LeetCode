class Solution {
public:

void dfs(vector<vector<char>>& grid, int i, int j) {
        // Base case: if the current cell is out of bounds or is water ('0'), stop
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') {
            return;
        }

        // Mark the current cell as visited by changing '1' to '0'
        grid[i][j] = '0';

        // Visit all adjacent cells (up, down, left, right)
        dfs(grid, i + 1, j); // down
        dfs(grid, i - 1, j); // up
        dfs(grid, i, j + 1); // right
        dfs(grid, i, j - 1); // left
    }
    int numIslands(vector<vector<char>>& grid) {
      if (grid.empty()) return 0;

        int numIslands = 0; // Initialize the number of islands

        // Iterate over every cell in the grid
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                // If the current cell is land ('1'), it represents a new island
                if (grid[i][j] == '1') {
                    ++numIslands;  // Found a new island, increment count
                    dfs(grid, i, j);  // Use DFS to mark the entire island as visited
                }
            }
        }

        return numIslands; // Return the total count of islands  
    }
};