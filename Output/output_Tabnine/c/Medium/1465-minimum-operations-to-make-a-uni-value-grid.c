/**https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/ */
//You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.
//A uni-value grid is a grid where all the elements of it are equal.
//Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.
// 
//Example 1:
//Input: grid = [[2,4],[6,8]], x = 2
//Output: 4
//Explanation: We can make every element equal to 4 by doing the following: 
//- Add x to 2 once.
//- Subtract x from 6 once.
//- Subtract x from 8 twice.
//A total of 4 operations were used.
//Example 2:
//Input: grid = [[1,5],[2,3]], x = 1
//Output: 5
//Explanation: We can make every element equal to 3.
//Example 3:
//Input: grid = [[1,2],[3,4]], x = 2
//Output: -1
//Explanation: It is impossible to make every element equal.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 105
//	1 <= m * n <= 105
//	1 <= x, grid[i][j] <= 104
int minOperations(int** grid, int gridSize, int* gridColSize, int x) {
    int rows = gridSize;
    int cols = gridColSize[0];
    int minOperations = INT_MAX;
    
    // Initialize a 2D dp array to store the minimum operations for each cell
    int** dp = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        dp[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            dp[i][j] = INT_MAX;
        }
    }
    
    // Base case: if the grid is already uni-value, return 0
    if (isUniValue(grid, rows, cols)) {
        return 0;
    }
    
    // Initialize the dp array with the minimum operations required to reach the current cell
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = abs(grid[i][j] - x);
            } else if (i == 0) {
                dp[i][j] = dp[i][j - 1] + abs(grid[i][j] - x);
            } else if (j == 0) {
                dp[i][j] = dp[i - 1][j] + abs(grid[i][j] - x);
            } else {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + abs(grid[i][j] - x);
            }
        }
    }
    
    // Find the minimum operations required to make the grid uni-value
    minOperations = dp[rows - 1][cols - 1];
    
    // Free the dp array
    for (int i = 0; i < rows; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return minOperations == INT_MAX? -1 : minOperations;
    
}