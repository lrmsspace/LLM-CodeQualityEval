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
 3 <= m == board.length <= 500
 3 <= n == board[i].length <= 500
 -109 <= board[i][j] <= 109
*/

class Solution {
    public long maximumValueSum(int[][] board) {
        int m = board.length;
        int n = board[0].length;
        long maxSum = Long.MIN_VALUE;

        // Iterate over all possible placements for the first rook
        for (int i1 = 0; i1 < m; ++i1) {
            for (int j1 = 0; j1 < n; ++j1) {
                // Iterate over all possible placements for the second rook
                for (int i2 = 0; i2 < m; ++i2) {
                    if (i2 == i1) continue; // Ensure rooks don't attack each other
                    for (int j2 = 0; j2 < n; ++j2) {
                        if (j2 == j1) continue; // Ensure rooks don't attack each other
                        // Iterate over all possible placements for the third rook
                        for (int i3 = 0; i3 < m; ++i3) {
                            if (i3 == i1 || i3 == i2) continue; // Ensure rooks don't attack each other
                            for (int j3 = 0; j3 < n; ++j3) {
                                if (j3 == j1 || j3 == j2) continue; // Ensure rooks don't attack each other
                                
                                // Calculate the sum for this placement
                                long currentSum = (long) board[i1][j1] + board[i2][j2] + board[i3][j3];
                                maxSum = Math.max(maxSum, currentSum);
                            }
                        }
                    }
                }
            }
        }

        return maxSum;

    }
}