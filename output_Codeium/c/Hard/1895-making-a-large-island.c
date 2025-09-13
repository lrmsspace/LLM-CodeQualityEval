/**https://leetcode.com/problems/making-a-large-island/ */
//You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
//Return the size of the largest island in grid after applying this operation.
//An island is a 4-directionally connected group of 1s.
// 
//Example 1:
//Input: grid = [[1,0],[0,1]]
//Output: 3
//Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
//Example 2:
//Input: grid = [[1,1],[1,0]]
//Output: 4
//Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
//Example 3:
//Input: grid = [[1,1],[1,1]]
//Output: 4
//Explanation: Can't change any 0 to 1, only one island with area = 4.
// 
//Constraints:
//	n == grid.length
//	n == grid[i].length
//	1 <= n <= 500
//	grid[i][j] is either 0 or 1.

int dfs(int** grid, int gridSize, int* gridColSize, int i, int j) {
    if (i < 0 || i >= gridSize || j < 0 || j >= *gridColSize || grid[i][j] != 1) {
        return 0;
    }
    grid[i][j] = 2;
    return 1 + dfs(grid, gridSize, gridColSize, i-1, j) + dfs(grid, gridSize, gridColSize, i+1, j) + dfs(grid, gridSize, gridColSize, i, j-1) + dfs(grid, gridSize, gridColSize, i, j+1);
}
int largestIsland(int** grid, int gridSize, int* gridColSize) {
    int max = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == 0) {
                grid[i][j] = 1;
                max = fmax(max, dfs(grid, gridSize, gridColSize, i, j));
                grid[i][j] = 0;
            }
        }
    }
    return max;
}   