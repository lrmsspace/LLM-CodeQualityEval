/**https://leetcode.com/problems/minimum-path-sum/ */
//Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
//Note: You can only move either down or right at any point in time.
// 
//Example 1:
//Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
//Output: 7
//Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
//Example 2:
//Input: grid = [[1,2,3],[4,5,6]]
//Output: 12
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 200
//	0 <= grid[i][j] <= 200
int minPathSum(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    int* dp = (int*)malloc(sizeof(int) * n);
    dp[0] = grid[0][0];
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + grid[0][i];
    }
    for (int i = 1; i < m; i++) {
        dp[0] += grid[i][0];
        for (int j = 1; j < n; j++) {
            dp[j] = fmin(dp[j], dp[j - 1]) + grid[i][j];
        }
    }
    int result = dp[n - 1];
    free(dp);
    return result;
}