#https://leetcode.com/problems/game-of-life/
#According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
#The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):
#	Any live cell with fewer than two live neighbors dies as if caused by under-population.
#	Any live cell with two or three live neighbors lives on to the next generation.
#	Any live cell with more than three live neighbors dies, as if by over-population.
#	Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
#The next state of the board is determined by applying the above rules simultaneously to every cell in the current state of the m x n grid board. In this process, births and deaths occur simultaneously.
#Given the current state of the board, update the board to reflect its next state.
#Note that you do not need to return anything.
# 
#Example 1:
#Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
#Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
#Example 2:
#Input: board = [[1,1],[1,0]]
#Output: [[1,1],[1,1]]
# 
#Constraints:
#	m == board.length
#	n == board[i].length
#	1 <= m, n <= 25
#	board[i][j] is 0 or 1.
# 
#Follow up:
#	Could you solve it in-place? Remember that the board needs to be updated simultaneously: You cannot update some cells first and then use their updated values to update other cells.
#	In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches upon the border of the array (i.e., live cells reach the border). How would you address these problems?
class Solution(object):
    def gameOfLife(self, board):
        """
        :type board: List[List[int]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        # 1: live cell, 0: dead cell, -1: live cell to be dead, 2: dead cell to be live
        # 1. Count the number of live neighbors for each cell
        # 2. Update the board according to the rules
        # 3. Convert -1 to 0 and 2 to 1
        rows, cols = len(board), len(board[0])
        for i in range(rows):
            for j in range(cols):
                live_neighbors = self.count_live_neighbors(board, i, j)
                if board[i][j] == 1 and (live_neighbors < 2 or live_neighbors > 3):
                    board[i][j] = -1
                elif board[i][j] == 0 and live_neighbors == 3:
                    board[i][j] = 2

        for i in range(rows):
            for j in range(cols):
                if board[i][j] == -1:
                    board[i][j] = 0
                elif board[i][j] == 2:
                    board[i][j] = 1   
                             