#https://leetcode.com/problems/n-queens-ii/
#The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
#Given an integer n, return the number of distinct solutions to the n-queens puzzle.
# 
#Example 1:
#Input: n = 4
#Output: 2
#Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
#Example 2:
#Input: n = 1
#Output: 1
# 
#Constraints:
#	1 <= n <= 9
class Solution(object):
    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: int
        """
        def is_valid(col, row, board):
            for i in range(row):
                if board[i][col] == 'Q':
                    return False
                if col - i >= 0 and board[i][col - i] == 'Q':
                    return False
                if col + i < n and board[i][col + i] == 'Q':
                    return False
            return True
        
        def backtrack(col, board):
            if col == n:
                nonlocal count
                count += 1
                return
            
            for row in range(n):
                if is_valid(col, row, board):
                    board[row][col] = 'Q'
                    backtrack(col + 1, board)
                    board[row][col] = '.'
        
        count = 0
        board = [['.' for _ in range(n)] for _ in range(n)]
        backtrack(0, board)
        return count
        