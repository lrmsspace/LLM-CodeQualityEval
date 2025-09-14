/**https://leetcode.com/problems/regions-cut-by-slashes/ */
//An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.
//Given the grid grid represented as a string array, return the number of regions.
//Note that backslash characters are escaped, so a '\' is represented as '\\'.
// 
//Example 1:
//Input: grid = [" /","/ "]
//Output: 2
//Example 2:
//Input: grid = [" /","  "]
//Output: 1
//Example 3:
//Input: grid = ["/\\","\\/"]
//Output: 5
//Explanation: Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.
// 
//Constraints:
//	n == grid.length == grid[i].length
//	1 <= n <= 30
//	grid[i][j] is either '/', '\', or ' '.  
class Solution {
    public:
        int regionsBySlashes(vector<string>& grid) {
            int n = grid.size();
            // Create a 3n x 3n grid to represent the subdivided cells
            vector<vector<int>> expanded(3 * n, vector<int>(3 * n, 0));
            
            // Fill the expanded grid based on the input
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == '/') {
                        // Mark the diagonal from top-right to bottom-left as blocked
                        expanded[3 * i][3 * j + 2] = 1;
                        expanded[3 * i + 1][3 * j + 1] = 1;
                        expanded[3 * i + 2][3 * j] = 1;
                    } else if (grid[i][j] == '\\') {
                        // Mark the diagonal from top-left to bottom-right as blocked
                        expanded[3 * i][3 * j] = 1;
                        expanded[3 * i + 1][3 * j + 1] = 1;
                        expanded[3 * i + 2][3 * j + 2] = 1;
                    }
                    // For blank spaces, leave the expanded grid as 0
                }
            }
            
            // Count regions using DFS
            int regions = 0;
            for (int i = 0; i < 3 * n; i++) {
                for (int j = 0; j < 3 * n; j++) {
                    if (expanded[i][j] == 0) {
                        dfs(expanded, i, j, 3 * n);
                        regions++;
                    }
                }
            }
            
            return regions;
        }
        
    private:
        void dfs(vector<vector<int>>& grid, int i, int j, int n) {
            // Check if the cell is out of bounds or already visited/blocked
            if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == 1) {
                return;
            }
            
            // Mark the cell as visited
            grid[i][j] = 1;
            
            // Explore the four adjacent cells
            dfs(grid, i + 1, j, n);
            dfs(grid, i - 1, j, n);
            dfs(grid, i, j + 1, n);
            dfs(grid, i, j - 1, n);
        }
    };
    
