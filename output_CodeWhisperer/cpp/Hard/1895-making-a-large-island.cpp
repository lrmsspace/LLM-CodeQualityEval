/**https://leetcode.com/problems/making-a-large-island/ */
//You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
//Return the size of the largest island in grid after applying this operation.
//An island is a 4-directionally connected group of 1s.
// 
//Example 1:
//Input: grid = [[1,0],[0,1]]
//Output: 3
//Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
//Example 2:
//Input: grid = [[1,1],[1,0]]
//Output: 4
//Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
//Example 3:
//Input: grid = [[1,1],[1,1]]
//Output: 4
//Explanation: Can't change any 0 to 1, only one island with area = 4.
// 
//Constraints:
//	n == grid.length
//	n == grid[i].length
//	1 <= n <= 500
//	grid[i][j] is either 0 or 1.    
class Solution {
    public:
        int largestIsland(vector<vector<int>>& grid) {
            int n = grid.size();
            if (n == 0) return 0;
            
            // Step 1: Label each island with a unique ID and calculate its size
            unordered_map<int, int> islandSizes; // Maps island ID to its size
            int islandId = 2; // Start from 2 to avoid confusion with 0s and 1s
            
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1) {
                        int size = dfs(grid, i, j, islandId);
                        islandSizes[islandId] = size;
                        islandId++;
                    }
                }
            }
            
            // If the entire grid is filled with 1s, return n*n
            if (islandSizes.size() == 1 && islandSizes.begin()->second == n * n) {
                return n * n;
            }
            
            // Step 2: Try changing each 0 to 1 and calculate the resulting island size
            int maxSize = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 0) {
                        // Get the set of adjacent island IDs
                        unordered_set<int> adjacentIslands;
                        
                        // Check all four directions
                        if (i > 0 && grid[i-1][j] > 1) adjacentIslands.insert(grid[i-1][j]);
                        if (i < n-1 && grid[i+1][j] > 1) adjacentIslands.insert(grid[i+1][j]);
                        if (j > 0 && grid[i][j-1] > 1) adjacentIslands.insert(grid[i][j-1]);
                        if (j < n-1 && grid[i][j+1] > 1) adjacentIslands.insert(grid[i][j+1]);
                        
                        // Calculate the total size after changing this 0 to 1
                        int totalSize = 1; // Start with 1 for the cell we're changing
                        for (int id : adjacentIslands) {
                            totalSize += islandSizes[id];
                        }
                        
                        maxSize = max(maxSize, totalSize);
                    }
                }
            }
            
            // If no 0s were found or changing any 0 doesn't increase the size,
            // return the size of the largest existing island
            if (maxSize == 0) {
                for (auto& pair : islandSizes) {
                    maxSize = max(maxSize, pair.second);
                }
            }
            
            return maxSize;
        }
        
    private:
        // DFS to label an island and calculate its size
        int dfs(vector<vector<int>>& grid, int i, int j, int islandId) {
            int n = grid.size();
            
            // Check if out of bounds or not part of the island
            if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1) {
                return 0;
            }
            
            // Mark this cell as part of the current island
            grid[i][j] = islandId;
            
            // Explore all four directions
            return 1 + dfs(grid, i+1, j, islandId) + 
                       dfs(grid, i-1, j, islandId) + 
                       dfs(grid, i, j+1, islandId) + 
                       dfs(grid, i, j-1, islandId);
        }
    };
    