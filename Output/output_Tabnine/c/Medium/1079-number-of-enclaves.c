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
int numEnclaves(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = *gridColSize;
    int count = 0;
    
    // Mark the boundary as visited
    for (int i = 0; i < m; i++) {
        dfs(grid, i, 0, m, n);
        dfs(grid, i, n - 1, m, n);
    }
    for (int j = 1; j < n - 1; j++) {
        dfs(grid, 0, j, m, n);
        dfs(grid, m - 1, j, m, n);
    }
    
    // Count the number of unvisited land cells
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 &&!visited[i][j]) {
                count++;
            }
        }
    }
    
    return count;
    
}