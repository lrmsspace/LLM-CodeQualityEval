#https://leetcode.com/problems/n-queens/
#The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
#Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
#Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
# 
#Example 1:
#Input: n = 4
#Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
#Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
#Example 2:
#Input: n = 1
#Output: [["Q"]]
# 
#Constraints:
#	1 <= n <= 9
class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        def is_safe(board, row, col):
            # Check if the current queen can be placed in the current row and column
            for i in range(col):
                # Check the left diagonal
                if board[row][i] == 'Q':
                    return False
                # Check the right diagonal
                if row + i < n and board[row + i][col] == 'Q':
                    return False
            return True
        
        def backtrack(board, col):
            # If all queens have been placed, add the solution to the result
            if col == n:
                result.append([''.join(row) for row in board])
                return
            
            # Try placing a queen in each row
            for row in range(n):
                # Check if the current row and column are safe
                if is_safe(board, row, col):
                    # Place the queen
                    board[row][col] = 'Q'
        
                    # Recursively solve the remaining columns
                    backtrack(board, col + 1)
        
                    # Remove the queen back to its original position
                    board[row][col] = '.'
        
        result = []
        # Initialize the board with empty spaces
        board = [['.' for _ in range(n)] for _ in range(n)]
        backtrack(board, 0)
        return result
        