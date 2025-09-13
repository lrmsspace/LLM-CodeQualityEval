/*
 You are given a m x n 2D array board representing a chessboard, where board[i][j] represents the value of the cell (i, j).
 Rooks in the same row or column attack each other. You need to place three rooks on the chessboard such that the rooks do not attack each other.
 Return the maximum sum of the cell values on which the rooks are placed.
 Example 1:
 Input: board = [[-3,1,1,1],[-3,1,-3,1],[-3,2,1,1]]
 Output: 4
 Explanation:
 We can place the rooks in the cells (0, 2), (1, 3), and (2, 1) for a sum of 1 + 1 + 2 = 4.
 Example 2:
 Input: board = [[1,2,3],[4,5,6],[7,8,9]]
 Output: 15
 Explanation:
 We can place the rooks in the cells (0, 0), (1, 1), and (2, 2) for a sum of 1 + 5 + 9 = 15.
 Example 3:
 Input: board = [[1,1,1],[1,1,1],[1,1,1]]
 Output: 3
 Explanation:
 We can place the rooks in the cells (0, 2), (1, 1), and (2, 0) for a sum of 1 + 1 + 1 = 3.
 Constraints:
 3 <= m == board.length <= 100
 3 <= n == board[i].length <= 100
 -109 <= board[i][j] <= 109
*/

class Solution {
    public long maximumValueSum(int[][] board) {
        int m = board.length;
        int n = board[0].length;
        long[][] dp = new long[m][n];
        dp[0][0] = board[0][0];
        dp[0][1] = board[0][1];
        dp[1][0] = board[1][0];
        dp[1][1] = board[1][1];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                if (i == 0) {
                    dp[i][j] = Math.max(dp[i][j - 1] + board[i][j], dp[i][j - 1] + board[i][j] * -1);
                } else if (j == 0) {
                    dp[i][j] = Math.max(dp[i - 1][j] + board[i][j], dp[i - 1][j] + board[i][j] * -1);
                } else {
                    dp[i][j] = Math.max(Math.max(dp[i - 1][j] + board[i][j], dp[i - 1][j] + board[i][j] * -1), Math.max(dp[i][j - 1] + board[i][j], dp[i][j - 1] + board[i][j] * -1));
                }
            }
        }
        return dp[m - 1][n - 1];        
    }
}