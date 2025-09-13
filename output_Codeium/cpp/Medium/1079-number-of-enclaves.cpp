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
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        // dfs from the boundary
        function<void(int, int)> dfs = [&](int x, int y) {
            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0 || visited[x][y]) return;
            visited[x][y] = true;
            dfs(x-1, y); dfs(x+1, y); dfs(x, y-1); dfs(x, y+1);
        };
        for (int i = 0; i < m; ++i) {
            dfs(i, 0); dfs(i, n-1);
        }
        for (int i = 0; i < n; ++i) {
            dfs(0, i); dfs(m-1, i);
        }
        
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) ++res;
            }
        }
        return res;
    }
};