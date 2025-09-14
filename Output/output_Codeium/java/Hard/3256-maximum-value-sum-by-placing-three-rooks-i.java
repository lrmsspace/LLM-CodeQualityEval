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
        long maxSum = Long.MIN_VALUE;
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                long sum = board[i][j];
                for (int k = 0; k < board.length; k++) {
                    if (k != i) {
                        sum += board[k][j];
                    }
                }
                for (int k = 0; k < board[i].length; k++) {
                    if (k != j) {
                        sum += board[i][k];
                    }
                }
                maxSum = Math.max(maxSum, sum);
            }
        }
        return maxSum;
    }
}