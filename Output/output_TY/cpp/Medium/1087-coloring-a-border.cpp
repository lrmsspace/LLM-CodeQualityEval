/**https://leetcode.com/problems/coloring-a-border/ */
//You are given an m x n integer matrix grid, and three integers row, col, and color. Each value in the grid represents the color of the grid square at that location.
//Two squares are called adjacent if they are next to each other in any of the 4 directions.
//Two squares belong to the same connected component if they have the same color and they are adjacent.
//The border of a connected component is all the squares in the connected component that are either adjacent to (at least) a square not in the component, or on the boundary of the grid (the first or last row or column).
//You should color the border of the connected component that contains the square grid[row][col] with color.
//Return the final grid.
// 
//Example 1:
//Input: grid = [[1,1],[1,2]], row = 0, col = 0, color = 3
//Output: [[3,3],[3,2]]
//Example 2:
//Input: grid = [[1,2,2],[2,3,2]], row = 0, col = 1, color = 3
//Output: [[1,3,3],[2,3,3]]
//Example 3:
//Input: grid = [[1,1,1],[1,1,1],[1,1,1]], row = 1, col = 1, color = 2
//Output: [[2,2,2],[2,1,2],[2,2,2]]
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 50
//	1 <= grid[i][j], color <= 1000
//	0 <= row < m
//	0 <= col < n
class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans = grid;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int startColor = grid[row][col];
        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = true;
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            bool isBorder = false;
            for (auto& dir : dirs) {
                int nx = x + dir[0], ny = y + dir[1];
                if (
                    nx < 0 || nx >= m || ny < 0 || ny >= n || 
                    grid[nx][ny] != startColor
                ) isBorder = true;
            }
            if (isBorder) ans[x][y] = color;
            for (auto& dir : dirs) {
                int nx = x + dir[0], ny = y + dir[1];
                if (
                    nx >= 0 && nx < m && ny >= 0 && ny < n && 
                    !visited[nx][ny] && grid[nx][ny] == startColor
                ) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
            visited[x][y] = true;
            ans[x][y] = startColor;
            startColor = ans[x][y];
        }
        return ans;
    }
};