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
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** colorBorder(int** grid, int gridSize, int* gridColSize, int row, int col, int color, int* returnSize, int** returnColumnSizes) {
    int m = gridSize, n = *gridColSize;
    int** result = malloc(m * sizeof(int*));
    *returnSize = m;
    *returnColumnSizes = malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        result[i] = malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
        for (int j = 0; j < n; j++) {
            result[i][j] = grid[i][j];
        }
    }
    
    int colorOfRowAbove = (row == 0)? 0 : grid[row - 1][col];
    int colorOfRowBelow = (row == m - 1)? 0 : grid[row + 1][col];
    int colorOfColLeft = (col == 0)? 0 : grid[row][col - 1];
    int colorOfColRight = (col == n - 1)? 0 : grid[row][col + 1];
    
    if (colorOfRowAbove == color || colorOfRowBelow == color || colorOfColLeft == color || colorOfColRight == color) {
        result[row][col] = color;
        dfs(grid, m, n, row, col, color, colorOfRowAbove, colorOfRowBelow, colorOfColLeft, colorOfColRight);
    }
    
    return result;
    
}