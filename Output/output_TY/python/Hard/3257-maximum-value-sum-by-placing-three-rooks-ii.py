# You are given a m x n 2D array board representing a chessboard, where board[i][j] represents the value of the cell (i, j).
# Rooks in the same row or column attack each other. You need to place three rooks on the chessboard such that the rooks do not attack each other.
# Return the maximum sum of the cell values on which the rooks are placed.
# Example 1:
# Input: board = [[-3,1,1,1],[-3,1,-3,1],[-3,2,1,1]]
# Output: 4
# Explanation:
# We can place the rooks in the cells (0, 2), (1, 3), and (2, 1) for a sum of 1 + 1 + 2 = 4.
# Example 2:
# Input: board = [[1,2,3],[4,5,6],[7,8,9]]
# Output: 15
# Explanation:
# We can place the rooks in the cells (0, 0), (1, 1), and (2, 2) for a sum of 1 + 5 + 9 = 15.
# Example 3:
# Input: board = [[1,1,1],[1,1,1],[1,1,1]]
# Output: 3
# Explanation:
# We can place the rooks in the cells (0, 2), (1, 1), and (2, 0) for a sum of 1 + 1 + 1 = 3.
# Constraints:
# 3 <= m == board.length <= 500
# 3 <= n == board[i].length <= 500
# -109 <= board[i][j] <= 109

class Solution(object):
    def maximumValueSum(self, board):
        """
        :type board: List[List[int]]
        :rtype: int
        """
        m = len(board)
        n = len(board[0])
        dp = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    dp[i][j] = board[i][j]
                elif i == 0:
                    dp[i][j] = dp[i][j - 1] + board[i][j]
                elif j == 0:
                    dp[i][j] = dp[i - 1][j] + board[i][j]
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + board[i][j]
        return dp[m - 1][n - 1]
        