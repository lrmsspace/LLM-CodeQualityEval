/**https://leetcode.com/problems/maximum-trailing-zeros-in-a-cornered-path/ */
//You are given a 2D integer array grid of size m x n, where each cell contains a positive integer.
//A cornered path is defined as a set of adjacent cells with at most one turn. More specifically, the path should exclusively move either horizontally or vertically up to the turn (if there is one), without returning to a previously visited cell. After the turn, the path will then move exclusively in the alternate direction: move vertically if it moved horizontally, and vice versa, also without returning to a previously visited cell.
//The product of a path is defined as the product of all the values in the path.
//Return the maximum number of trailing zeros in the product of a cornered path found in grid.
//Note:
//	Horizontal movement means moving in either the left or right direction.
//	Vertical movement means moving in either the up or down direction.
// 
//Example 1:
//Input: grid = [[23,17,15,3,20],[8,1,20,27,11],[9,4,6,2,21],[40,9,1,10,6],[22,7,4,5,3]]
//Output: 3
//Explanation: The grid on the left shows a valid cornered path.
//It has a product of 15 * 20 * 6 * 1 * 10 = 18000 which has 3 trailing zeros.
//It can be shown that this is the maximum trailing zeros in the product of a cornered path.
//The grid in the middle is not a cornered path as it has more than one turn.
//The grid on the right is not a cornered path as it requires a return to a previously visited cell.
//Example 2:
//Input: grid = [[4,3,2],[7,6,1],[8,8,8]]
//Output: 0
//Explanation: The grid is shown in the figure above.
//There are no cornered paths in the grid that result in a product with a trailing zero.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 105
//	1 <= m * n <= 105
//	1 <= grid[i][j] <= 1000 
int maxTrailingZeros(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    
    // Create arrays to store prefix sums of factors 2 and 5
    int*** rowPrefix = (int***)malloc(m * sizeof(int**));
    int*** colPrefix = (int***)malloc(m * sizeof(int**));
    
    for (int i = 0; i < m; i++) {
        rowPrefix[i] = (int**)malloc(n * sizeof(int*));
        colPrefix[i] = (int**)malloc(n * sizeof(int*));
        for (int j = 0; j < n; j++) {
            rowPrefix[i][j] = (int*)calloc(2, sizeof(int));
            colPrefix[i][j] = (int*)calloc(2, sizeof(int));
        }
    }
    
    // Calculate row prefixes (horizontal)
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int val = grid[i][j];
            rowPrefix[i][j][0] = countFactors(val, 2);
            rowPrefix[i][j][1] = countFactors(val, 5);
            
            if (j > 0) {
                rowPrefix[i][j][0] += rowPrefix[i][j-1][0];
                rowPrefix[i][j][1] += rowPrefix[i][j-1][1];
            }
        }
    }
    
    // Calculate column prefixes (vertical)
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            int val = grid[i][j];
            colPrefix[i][j][0] = countFactors(val, 2);
            colPrefix[i][j][1] = countFactors(val, 5);
            
            if (i > 0) {
                colPrefix[i][j][0] += colPrefix[i-1][j][0];
                colPrefix[i][j][1] += colPrefix[i-1][j][1];
            }
        }
    }
    
    int result = 0;
    
    // Check all possible cornered paths with each cell as the turning point
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int curr2 = countFactors(grid[i][j], 2);
            int curr5 = countFactors(grid[i][j], 5);
            
            // Top-left path
            int top2 = (i > 0) ? colPrefix[i-1][j][0] : 0;
            int top5 = (i > 0) ? colPrefix[i-1][j][1] : 0;
            int left2 = (j > 0) ? rowPrefix[i][j-1][0] : 0;
            int left5 = (j > 0) ? rowPrefix[i][j-1][1] : 0;
            
            // Top-right path
            int right2 = rowPrefix[i][n-1][0] - rowPrefix[i][j][0] + curr2;
            int right5 = rowPrefix[i][n-1][1] - rowPrefix[i][j][1] + curr5;
            
            // Bottom-left path
            int bottom2 = colPrefix[m-1][j][0] - colPrefix[i][j][0] + curr2;
            int bottom5 = colPrefix[m-1][j][1] - colPrefix[i][j][1] + curr5;
            
            // Check all possible paths
            result = max(result, min(top2 + left2 + curr2, top5 + left5 + curr5));
            result = max(result, min(top2 + right2, top5 + right5));
            result = max(result, min(bottom2 + left2, bottom5 + left5));
            result = max(result, min(bottom2 + right2 - curr2, bottom5 + right5 - curr5));
        }
    }
    
    // Free allocated memory
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            free(rowPrefix[i][j]);
            free(colPrefix[i][j]);
        }
        free(rowPrefix[i]);
        free(colPrefix[i]);
    }
    free(rowPrefix);
    free(colPrefix);
    
    return result;
}
