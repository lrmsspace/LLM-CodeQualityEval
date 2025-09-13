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
        def could_place(row, col):
            """
            Check if a queen can be placed on board[row][col]. This function is called when "col" queens are already placed in columns from 0 to col - 1. So we need to check only left side for attacking queens.
            """
            for i in range(col):
                if board[row][i] == 'Q':
                    return False
            for i, j in zip(range(row-1, -1, -1), range(col-1, -1, -1)):
                if board[i][j] == 'Q':
                    return False
            for i, j in zip(range(row+1, n, 1), range(col-1, -1, -1)):
                if board[i][j] == 'Q':
                    return False
            return True
        
        def backtrack(row, count):
            """
            Backtracking function to solve the n-queens problem.
            """
            for col in range(n):
                if could_place(row, col):
                    board[row][col] = 'Q'
                    if row + 1 == n:
                        nonlocal solutions
                        solutions += 1
                    else:
                        backtrack(row + 1, count + 1)
                    board[row][col] = '.'
        
        board = [['.'] * n for _ in range(n)]
        solutions = 0
        backtrack(0, 0)
        return solutions
        