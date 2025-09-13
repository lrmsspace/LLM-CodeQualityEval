/**https://leetcode.com/problems/escape-the-spreading-fire/ */
//You are given a 0-indexed 2D integer array grid of size m x n which represents a field. Each cell has one of three values:
//	0 represents grass,
//	1 represents fire,
//	2 represents a wall that you and fire cannot pass through.
//You are situated in the top-left cell, (0, 0), and you want to travel to the safehouse at the bottom-right cell, (m - 1, n - 1). Every minute, you may move to an adjacent grass cell. After your move, every fire cell will spread to all adjacent cells that are not walls.
//Return the maximum number of minutes that you can stay in your initial position before moving while still safely reaching the safehouse. If this is impossible, return -1. If you can always reach the safehouse regardless of the minutes stayed, return 109.
//Note that even if the fire spreads to the safehouse immediately after you have reached it, it will be counted as safely reaching the safehouse.
//A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).
// 
//Example 1:
//Input: grid = [[0,2,0,0,0,0,0],[0,0,0,2,2,1,0],[0,2,0,0,1,2,0],[0,0,2,2,2,0,2],[0,0,0,0,0,0,0]]
//Output: 3
//Explanation: The figure above shows the scenario where you stay in the initial position for 3 minutes.
//You will still be able to safely reach the safehouse.
//Staying for more than 3 minutes will not allow you to safely reach the safehouse.
//Example 2:
//Input: grid = [[0,0,0,0],[0,1,2,0],[0,2,0,0]]
//Output: -1
//Explanation: The figure above shows the scenario where you immediately move towards the safehouse.
//Fire will spread to any cell you move towards and it is impossible to safely reach the safehouse.
//Thus, -1 is returned.
//Example 3:
//Input: grid = [[0,0,0],[2,2,0],[1,2,0]]
//Output: 1000000000
//Explanation: The figure above shows the initial grid.
//Notice that the fire is contained by walls and you will always be able to safely reach the safehouse.
//Thus, 109 is returned.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	2 <= m, n <= 300
//	4 <= m * n <= 2 * 104
//	grid[i][j] is either 0, 1, or 2.
//	grid[0][0] == grid[m - 1][n - 1] == 0   
class Solution {
    public:
        int maximumMinutes(vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
            
            // Calculate fire spread times
            vector<vector<int>> fireTime = calculateFireSpreadTime(grid);
            
            // Calculate person's shortest path time without waiting
            vector<vector<int>> personTime = calculatePersonTime(grid);
            
            // If person cannot reach safehouse
            if (personTime[m-1][n-1] == INT_MAX) {
                return -1;
            }
            
            // If fire cannot reach safehouse
            if (fireTime[m-1][n-1] == INT_MAX) {
                return 1e9;
            }
            
            // Binary search for the maximum waiting time
            int left = 0;
            int right = 1e9;
            int result = -1;
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                
                if (canReachSafehouse(grid, fireTime, mid)) {
                    result = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            
            return result;
        }
        
    private:
        // Directions: up, right, down, left
        const vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        vector<vector<int>> calculateFireSpreadTime(const vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
            
            vector<vector<int>> fireTime(m, vector<int>(n, INT_MAX));
            queue<pair<int, int>> q;
            
            // Initialize fire positions
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1) {
                        q.push({i, j});
                        fireTime[i][j] = 0;
                    } else if (grid[i][j] == 2) {
                        // Mark walls as unreachable
                        fireTime[i][j] = -1;
                    }
                }
            }
            
            // BFS for fire spread
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                
                for (const auto& [dx, dy] : dirs) {
                    int nx = x + dx;
                    int ny = y + dy;
                    
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && 
                        grid[nx][ny] == 0 && fireTime[nx][ny] == INT_MAX) {
                        fireTime[nx][ny] = fireTime[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
            
            return fireTime;
        }
        
        vector<vector<int>> calculatePersonTime(const vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
            
            vector<vector<int>> personTime(m, vector<int>(n, INT_MAX));
            queue<pair<int, int>> q;
            
            // Start from (0, 0)
            q.push({0, 0});
            personTime[0][0] = 0;
            
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                
                for (const auto& [dx, dy] : dirs) {
                    int nx = x + dx;
                    int ny = y + dy;
                    
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && 
                        grid[nx][ny] == 0 && personTime[nx][ny] == INT_MAX) {
                        personTime[nx][ny] = personTime[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
            
            return personTime;
        }
        
        bool canReachSafehouse(const vector<vector<int>>& grid, const vector<vector<int>>& fireTime, int waitTime) {
            int m = grid.size();
            int n = grid[0].size();
            
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            queue<pair<int, pair<int, int>>> q; // (time, (x, y))
            
            // Start from (0, 0) after waiting for 'waitTime'
            q.push({waitTime, {0, 0}});
            visited[0][0] = true;
            
            while (!q.empty()) {
                auto [time, pos] = q.front();
                int x = pos.first;
                int y = pos.second;
                q.pop();
                
                // If fire has already reached this cell
                if (fireTime[x][y] <= time) {
                    continue;
                }
                
                // If we've reached the safehouse
                if (x == m - 1 && y == n - 1) {
                    return true;
                }
                
                // Try all four directions
                for (const auto& [dx, dy] : dirs) {
                    int nx = x + dx;
                    int ny = y + dy;
                    int newTime = time + 1;
                    
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && 
                        grid[nx][ny] == 0 && !visited[nx][ny] && fireTime[nx][ny] > newTime) {
                        q.push({newTime, {nx, ny}});
                        visited[nx][ny] = true;
                    }
                }
            }
            
            return false;
        }
    };
    