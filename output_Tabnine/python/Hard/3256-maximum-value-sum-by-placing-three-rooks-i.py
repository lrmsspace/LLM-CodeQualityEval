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
# 3 <= m == board.length <= 100
# 3 <= n == board[i].length <= 100
# -109 <= board[i][j] <= 109

class Solution(object):
    def maximumValueSum(self, board):
        """
        :type board: List[List[int]]
        :rtype: int
        """
        # Initialize variables
        m, n = len(board), len(board[0])
        rooks = []
        max_sum = float('-inf')
        
        # Helper function to check if a cell is valid for a rook
        def is_valid(row, col):
            return 0 <= row < m and 0 <= col < n
        
        # Helper function to backtrack and place rooks
        def backtrack(row, col):
            nonlocal max_sum
            
            # If all rooks are placed, calculate the sum and update max_sum
            if len(rooks) == 3:
                curr_sum = sum(board[i][j] for i, j in rooks)
                max_sum = max(max_sum, curr_sum)
                return
            
            # Place rook in each cell and backtrack

            # Place rook in current cell
            rooks.append((row, col))
            
            # Place rook in adjacent cells
            for dr, dc in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                new_row, new_col = row + dr, col + dc
                if is_valid(new_row, new_col) and (new_row, new_col) not in rooks:
                    backtrack(new_row, new_col)
            
            # Remove rook from current cell and backtrack
            rooks.pop()
            return  
        