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
        int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int m = matrix.length, n = matrix[0].length;
        int[][] dp = new int[m][n];
        
        int dfs(int i, int j) {
            if (dp[i][j] != 0) return dp[i][j];
            int max = 1;
            for (int[] d : directions) {
                int x = i + d[0], y = j + d[1];
                if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
                    max = Math.max(max, 1 + dfs(x, y));
                }
            }
            dp[i][j] = max;
            return max;
        }
        int max = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                max = Math.max(max, dfs(i, j));
            }
        }
        return max;
        
    }
}