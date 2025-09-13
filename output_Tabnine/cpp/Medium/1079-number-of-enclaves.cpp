/**https://leetcode.com/problems/number-of-enclaves/ */
//You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
//A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
//Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
// 
//Example 1:
//Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
//Output: 3
//Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
//Example 2:
//Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
//Output: 0
//Explanation: All 1s are either on the boundary or can reach the boundary.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 500
//	grid[i][j] is either 0 or 1.
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 1) q.push({i, 0});
            if (grid[i][n - 1] == 1) q.push({i, n - 1});
        }
        for (int j = 1; j < n - 1; ++j) {
            if (grid[0][j] == 1) q.push({0, j});
            if (grid[m - 1][j] == 1) q.push({m - 1, j});
        }
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            if (grid[x][y] == 0) continue;
            grid[x][y] = 0;
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    int nx = x + dx, ny = y + dy;
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == 0) continue;
                    q.push({nx, ny});
                }
            }
        }
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                count += grid[i][j];
            }
        }
        return count;
        
    }
};