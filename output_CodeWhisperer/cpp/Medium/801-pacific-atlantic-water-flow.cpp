/**https://leetcode.com/problems/pacific-atlantic-water-flow/ */
//There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.
//The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).
//The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.
//Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.
// 
//Example 1:
//Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
//Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
//Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
//[0,4]: [0,4] -> Pacific Ocean 
//       [0,4] -> Atlantic Ocean
//[1,3]: [1,3] -> [0,3] -> Pacific Ocean 
//       [1,3] -> [1,4] -> Atlantic Ocean
//[1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean 
//       [1,4] -> Atlantic Ocean
//[2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean 
//       [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
//[3,0]: [3,0] -> Pacific Ocean 
//       [3,0] -> [4,0] -> Atlantic Ocean
//[3,1]: [3,1] -> [3,0] -> Pacific Ocean 
//       [3,1] -> [4,1] -> Atlantic Ocean
//[4,0]: [4,0] -> Pacific Ocean 
//       [4,0] -> Atlantic Ocean
//Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.
//Example 2:
//Input: heights = [[1]]
//Output: [[0,0]]
//Explanation: The water can flow from the only cell to the Pacific and Atlantic oceans.
// 
//Constraints:
//	m == heights.length
//	n == heights[r].length
//	1 <= m, n <= 200
//	0 <= heights[r][c] <= 105   
class Solution {
    public:
        vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
            if (heights.empty() || heights[0].empty()) {
                return {};
            }
            
            int m = heights.size();
            int n = heights[0].size();
            
            // Create two matrices to track cells reachable from each ocean
            vector<vector<bool>> pacific(m, vector<bool>(n, false));
            vector<vector<bool>> atlantic(m, vector<bool>(n, false));
            
            // Define the four possible directions: up, right, down, left
            vector<int> dx = {-1, 0, 1, 0};
            vector<int> dy = {0, 1, 0, -1};
            
            // Use BFS to mark cells reachable from each ocean
            queue<pair<int, int>> pacificQueue, atlanticQueue;
            
            // Add Pacific edge cells to the queue
            for (int i = 0; i < m; i++) {
                pacificQueue.push({i, 0});
                pacific[i][0] = true;
            }
            for (int j = 1; j < n; j++) {
                pacificQueue.push({0, j});
                pacific[0][j] = true;
            }
            
            // Add Atlantic edge cells to the queue
            for (int i = 0; i < m; i++) {
                atlanticQueue.push({i, n - 1});
                atlantic[i][n - 1] = true;
            }
            for (int j = 0; j < n - 1; j++) {
                atlanticQueue.push({m - 1, j});
                atlantic[m - 1][j] = true;
            }
            
            // BFS from Pacific edges
            bfs(heights, pacific, pacificQueue, m, n, dx, dy);
            
            // BFS from Atlantic edges
            bfs(heights, atlantic, atlanticQueue, m, n, dx, dy);
            
            // Find cells that can reach both oceans
            vector<vector<int>> result;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (pacific[i][j] && atlantic[i][j]) {
                        result.push_back({i, j});
                    }
                }
            }
            
            return result;
        }
        
    private:
        void bfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, 
                 queue<pair<int, int>>& q, int m, int n, vector<int>& dx, vector<int>& dy) {
            while (!q.empty()) {
                auto [i, j] = q.front();
                q.pop();
                
                // Check all four adjacent cells
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    
                    // Skip if out of bounds, already visited, or lower height
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n || 
                        visited[ni][nj] || heights[ni][nj] < heights[i][j]) {
                        continue;
                    }
                    
                    visited[ni][nj] = true;
                    q.push({ni, nj});
                }
            }
        }
    };
    