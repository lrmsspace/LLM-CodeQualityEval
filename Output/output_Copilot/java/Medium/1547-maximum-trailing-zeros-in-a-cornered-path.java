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
class Solution {
    public int maxTrailingZeros(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][][] dp = new int[m][n][2];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j][0] = grid[i][j];
                dp[i][j][1] = grid[i][j];
                if (i > 0) {
                    dp[i][j][0] = Math.max(dp[i][j][0], dp[i - 1][j][0] * grid[i][j]);
                    dp[i][j][1] = Math.min(dp[i][j][1], dp[i - 1][j][1] * grid[i][j]);
                }
                if (j > 0) {
                    dp[i][j][0] = Math.max(dp[i][j][0], dp[i][j - 1][0] * grid[i][j]);
                    dp[i][j][1] = Math.min(dp[i][j][1], dp[i][j - 1][1] * grid[i][j]);
                }
            }
        }
        int res = 0;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int max = dp[i][j][0];
                int min = dp[i][j][1];
                if (i < m - 1) {
                    max = Math.max(max, dp[i + 1][j][0] * grid[i][j]);
                    min = Math.min(min, dp[i + 1][j][1] * grid[i][j]);
                }
                if (j < n - 1) {
                    max = Math.max(max, dp[i][j + 1][0] * grid[i][j]);
                    min = Math.min(min, dp[i][j + 1][1] * grid[i][j]);
                }
                res = Math.max(res, countZero(max));
                res = Math.max(res, countZero(min));
            }
        }
        return res;        
    }
}