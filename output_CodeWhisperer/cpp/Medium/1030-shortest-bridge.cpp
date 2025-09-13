/**https://leetcode.com/problems/shortest-bridge/ */
//You are given an n x n binary matrix grid where 1 represents land and 0 represents water.
//An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.
//You may change 0's to 1's to connect the two islands to form one island.
//Return the smallest number of 0's you must flip to connect the two islands.
// 
//Example 1:
//Input: grid = [[0,1],[1,0]]
//Output: 1
//Example 2:
//Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
//Output: 2
//Example 3:
//Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
//Output: 1
// 
//Constraints:
//	n == grid.length == grid[i].length
//	2 <= n <= 100
//	grid[i][j] is either 0 or 1.
//	There are exactly two islands in grid.  
class Solution {
    public:
        int shortestBridge(vector<vector<int>>& grid) {
            int n = grid.size();
            queue<pair<int, int>> q;
            vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
            
            // Find and mark the first island
            bool found = false;
            for (int i = 0; i < n && !found; i++) {
                for (int j = 0; j < n && !found; j++) {
                    if (grid[i][j] == 1) {
                        markIsland(grid, i, j, q);
                        found = true;
                    }
                }
            }
            
            // BFS to find the shortest path to the second island
            int steps = 0;
            
            while (!q.empty()) {
                int size = q.size();
                
                for (int i = 0; i < size; i++) {
                    auto [x, y] = q.front();
                    q.pop();
                    
                    for (auto& dir : dirs) {
                        int nx = x + dir[0];
                        int ny = y + dir[1];
                        
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                            if (grid[nx][ny] == 1) {
                                // Found the second island
                                return steps;
                            } else if (grid[nx][ny] == 0) {
                                // Mark as visited and add to queue
                                grid[nx][ny] = 2;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
                
                steps++;
            }
            
            return -1; // Should not reach here if there are exactly two islands
        }
        
    private:
        void markIsland(vector<vector<int>>& grid, int i, int j, queue<pair<int, int>>& q) {
            int n = grid.size();
            
            if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1) {
                return;
            }
            
            // Mark as visited
            grid[i][j] = 2;
            // Add to queue for BFS
            q.push({i, j});
            
            // Continue DFS in all four directions
            markIsland(grid, i + 1, j, q);
            markIsland(grid, i - 1, j, q);
            markIsland(grid, i, j + 1, q);
            markIsland(grid, i, j - 1, q);
        }
    };
    