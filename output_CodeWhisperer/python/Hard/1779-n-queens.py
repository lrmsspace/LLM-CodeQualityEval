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
        def could_place(row, col):
            """
            Check if a queen can be placed on board[row][col].
            This function is called when "col" queens are already placed in columns from 0 to col - 1.
            So we need to check only left side for attacking queens.
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
                        add_solution()
                    else:
                        backtrack(row + 1, count + 1)
                    board[row][col] = '.'
        
        def add_solution():
            """
            Add the current board configuration to the list of solutions.
            """
            solution = []
            for row in range(n):
                solution.append(''.join(board[row]))
            solutions.append(solution)
        
        board = [['.'] * n for _ in range(n)]
        solutions = []
        backtrack(0, 0)
        return solutions
        