/**https://leetcode.com/problems/detect-cycles-in-2d-grid/ */
//Given a 2D array of characters grid of size m x n, you need to find if there exists any cycle consisting of the same value in grid.
//A cycle is a path of length 4 or more in the grid that starts and ends at the same cell. From a given cell, you can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or right), if it has the same value of the current cell.
//Also, you cannot move to the cell that you visited in your last move. For example, the cycle (1, 1) -> (1, 2) -> (1, 1) is invalid because from (1, 2) we visited (1, 1) which was the last visited cell.
//Return true if any cycle of the same value exists in grid, otherwise, return false.
// 
//Example 1:
//Input: grid = [["a","a","a","a"],["a","b","b","a"],["a","b","b","a"],["a","a","a","a"]]
//Output: true
//Explanation: There are two valid cycles shown in different colors in the image below:
//Example 2:
//Input: grid = [["c","c","c","a"],["c","d","c","c"],["c","c","e","c"],["f","c","c","c"]]
//Output: true
//Explanation: There is only one valid cycle highlighted in the image below:
//Example 3:
//Input: grid = [["a","b","b"],["b","z","b"],["b","b","a"]]
//Output: false
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 500
//	grid consists only of lowercase English letters.
class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        function<bool(int, int, int, int)> dfs = [&](int x, int y, int px, int py) {
            visited[x][y] = 1;
            for (auto &dir : directions) {
                int nx = x + dir[0], ny = y + dir[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == grid[x][y]) {
                    if (visited[nx][ny] == 1 && (nx != px || ny != py)) {
                        return true;
                    }
                    if (visited[nx][ny] == 0 && dfs(nx, ny, x, y)) {
                        return true;
                    }
                }
            }
            visited[x][y] = 2;
            return false;
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visited[i][j] == 0 && dfs(i, j, -1, -1)) {
                    return true;
                }
            }
        }
        return false;        
    }
};