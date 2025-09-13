/**https://leetcode.com/problems/longest-increasing-path-in-a-matrix/ */
//Given an m x n integers matrix, return the length of the longest increasing path in matrix.
//From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).
// 
//Example 1:
//Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
//Output: 4
//Explanation: The longest increasing path is [1, 2, 6, 9].
//Example 2:
//Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
//Output: 4
//Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
//Example 3:
//Input: matrix = [[1]]
//Output: 1
// 
//Constraints:
//	m == matrix.length
//	n == matrix[i].length
//	1 <= m, n <= 200
//	0 <= matrix[i][j] <= 231 - 1
class Solution {
    public int longestIncreasingPath(int[][] matrix) {
            int m = matrix.length;
        int n = matrix[0].length;
        int[][] dp = new int[m][n];
        int max = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                max = Math.max(max, dfs(matrix, dp, i, j));
            }
        }
        return max;
    }

    private int dfs(int[][] matrix, int[][] dp, int i, int j) {
        if (dp[i][j] != 0) return dp[i][j];
        int m = matrix.length;
        int n = matrix[0].length;
        if (i > 0 && matrix[i][j] > matrix[i - 1][j]) {
            dp[i][j] = Math.max(dp[i][j], dfs(matrix, dp, i - 1, j) + 1);
        }
        if (i < m - 1 && matrix[i][j] > matrix[i + 1][j]) {
            dp[i][j] = Math.max(dp[i][j], dfs(matrix, dp, i + 1, j) + 1);
        }
        if (j > 0 && matrix[i][j] > matrix[i][j - 1]) {
            dp[i][j] = Math.max(dp[i][j], dfs(matrix, dp, i, j - 1)) + 1;
        }
        if (j < n - 1 && matrix[i][j] > matrix[i][j + 1]) {
            dp[i][j] = Math.max(dp[i][j], dfs(matrix, dp, i, j + 1) + 1);
        }
        return dp[i][j];
    }
}