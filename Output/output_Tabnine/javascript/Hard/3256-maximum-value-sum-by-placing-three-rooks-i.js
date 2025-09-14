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

/**
 * @param {number[][]} board
 * @return {number}
 */
var maximumValueSum = function(board) {
    const m = board.length;
    const n = board[0].length;
    const dp = Array.from({ length: m }, () => Array(n).fill(0));

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (i > 0) {
                dp[i][j] = Math.max(dp[i][j], dp[i - 1][j] + board[i][j]);
            }
            if (j > 0) {
                dp[i][j] = Math.max(dp[i][j], dp[i][j - 1] + board[i][j]);
            }
        }
    }

    let maxSum = 0;

    for (let i = 1; i < m - 1; i++) {
        for (let j = 1; j < n - 1; j++) {
            maxSum = Math.max(maxSum, dp[i - 1][j - 1] + dp[i + 1][j + 1] + board[i][j]);
        }
    }

    return maxSum;
};