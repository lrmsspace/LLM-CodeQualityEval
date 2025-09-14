#https://leetcode.com/problems/sudoku-solver/
#Write a program to solve a Sudoku puzzle by filling the empty cells.
#A sudoku solution must satisfy all of the following rules:
#	Each of the digits 1-9 must occur exactly once in each row.
#	Each of the digits 1-9 must occur exactly once in each column.
#	Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
#The '.' character indicates empty cells.
# 
#Example 1:
#Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
#Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
#Explanation: The input board is shown above and the only valid solution is shown below:
# 
#Constraints:
#	board.length == 9
#	board[i].length == 9
#	board[i][j] is a digit or '.'.
#	It is guaranteed that the input board has only one solution.
class Solution(object):
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        def isValid(row, col, num):
            for i in range(9):
                if board[row][i] == num or board[i][col] == num:
                    return False
            startRow, startCol = 3 * (row // 3), 3 * (col // 3)
            for i in range(3):
                for j in range(3):
                    if board[i + startRow][j + startCol] == num:
                        return False
            return True
        def backtrack(row, col):
            if row == 9:
                return True
            if col == 9:
                return backtrack(row + 1, 0)
            if board[row][col] != ".":
                return backtrack(row, col + 1)
            for num in "123456789":
                if isValid(row, col, num):
                    board[row][col] = num
                    if backtrack(row, col + 1):
                        return True
                    board[row][col] = "."
            return False
        backtrack(0, 0)
        return board