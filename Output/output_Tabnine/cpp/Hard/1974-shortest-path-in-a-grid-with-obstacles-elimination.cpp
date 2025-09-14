/**https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/ */
//You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). You can move up, down, left, or right from and to an empty cell in one step.
//Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.
// 
//Example 1:
//Input: grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
//Output: 6
//Explanation: 
//The shortest path without eliminating any obstacle is 10.
//The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).
//Example 2:
//Input: grid = [[0,1,1],[1,1,1],[1,0,0]], k = 1
//Output: -1
//Explanation: We need to eliminate at least two obstacles to find such a walk.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 40
//	1 <= k <= m * n
//	grid[i][j] is either 0 or 1.
//	grid[0][0] == grid[m - 1][n - 1] == 0
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        q.push({0, 0});
        
        vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
        
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            
            if (x == m - 1 && y == n - 1) return dist[x][y];
            
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 0 && dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
    
            for (int i = 0; i <= k; ++i) {
                for (int j = 0; j < m; ++j) {
                    for (int l = 0; l < n; ++l) {
                        if (grid[j][l] == 1) {
                            grid[j][l] = 0;
                            if (nx >= 0 && nx < m && ny >= 0 && ny < n && dist[nx][ny] > dist[j][l] + 1) {
                                dist[nx][ny] = dist[j][l] + 1;
                                q.push({nx, ny});
                            }
                            grid[j][l] = 1;
                        }
                    }
                }
            }
    
            if (q.empty()) return -1;
        }
        
        return -1;
        
    }
};