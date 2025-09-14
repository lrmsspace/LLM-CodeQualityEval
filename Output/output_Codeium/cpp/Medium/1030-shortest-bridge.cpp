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
        vector<vector<int>> visited(n, vector<int>(n, 0));
        queue<pair<int, int>> q;
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int res = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    q.push({i, j});
                    visited[i][j] = 1;
                    while (!q.empty()) {
                        int x = q.front().first, y = q.front().second; q.pop();
                        for (int k = 0; k < 4; ++k) {
                            int nx = x + dir[k][0], ny = y + dir[k][1];
                            if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 1 && !visited[nx][ny]) {
                                q.push({nx, ny});
                                visited[nx][ny] = 1;
                            }
                        }
                    }
                    break;
                }
            }
            if (visited[i][0] == 1) break;
        }
        
        queue<pair<int, int>> q2;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && visited[i][j] == 1) {
                    q2.push({i, j});
                    break;
                }
            }
            if (!q2.empty()) break;
        }
        
        while (!q2.empty()) {
            int x = q2.front().first, y = q2.front().second; q2.pop();
            for (int k = 0; k < 4; ++k) {
                int nx = x + dir[k][0], ny = y + dir[k][1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 1 && !visited[nx][ny]) {
                    q2.push({nx, ny});
                    visited[nx][ny] = 1;
                }
            }
            if (q2.empty()) break;
            ++res;
        }
        
        return res;
    }
};