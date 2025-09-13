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

void dfs(int** grid, int i, int j, int gridSize, int* gridColSize) {
    if (i < 0 || i >= gridSize || j < 0 || j >= *gridColSize || grid[i][j] == 0 || grid[i][j] == -1) {
        return;
    }
    grid[i][j] = -1;
    dfs(grid, i + 1, j, gridSize, gridColSize);
    dfs(grid, i - 1, j, gridSize, gridColSize);
    dfs(grid, i, j + 1, gridSize, gridColSize);
    dfs(grid, i, j - 1, gridSize, gridColSize);
}
int numEnclaves(int** grid, int gridSize, int* gridColSize) {
    int res = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == 1) {
                dfs(grid, i, j, gridSize, gridColSize);
                res++;
            }
        }
    }
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == -1) {
                dfs(grid, i, j, gridSize, gridColSize);
                res--;
            }
        }
    }
    return res;
}   