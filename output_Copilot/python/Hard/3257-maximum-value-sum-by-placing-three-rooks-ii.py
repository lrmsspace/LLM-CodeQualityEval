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
        m, n = len(board), len(board[0])
        max_sum = float('-inf')
        
        # Iterate through all combinations of three distinct rows and columns
        for i in range(m):
            for j in range(n):
                for k in range(m):
                    if k == i:
                        continue
                    for l in range(n):
                        if l == j:
                            continue
                        for p in range(m):
                            if p == i or p == k:
                                continue
                            for q in range(n):
                                if q == j or q == l:
                                    continue
                                current_sum = board[i][j] + board[k][l] + board[p][q]
                                max_sum = max(max_sum, current_sum)
        
        return max_sum
        