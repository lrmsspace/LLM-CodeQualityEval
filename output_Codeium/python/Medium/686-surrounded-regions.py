#https://leetcode.com/problems/surrounded-regions/
#You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:
#	Connect: A cell is connected to adjacent cells horizontally or vertically.
#	Region: To form a region connect every 'O' cell.
#	Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
#A surrounded region is captured by replacing all 'O's with 'X's in the input matrix board.
# 
#Example 1:
#Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
#Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
#Explanation:
#In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.
#Example 2:
#Input: board = [["X"]]
#Output: [["X"]]
# 
#Constraints:
#	m == board.length
#	n == board[i].length
#	1 <= m, n <= 200
#	board[i][j] is 'X' or 'O'.
class Solution(object):
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        if not board:
            return
        m, n = len(board), len(board[0])
        #mark the 'O' region connected to the edge of the board
        for i in range(m):
            self.dfs(board, i, 0)
            self.dfs(board, i, n-1)
        for j in range(n):
            self.dfs(board, 0, j)
            self.dfs(board, m-1, j)
        #capture the surrounded regions
        for i in range(m):
            for j in range(n):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
                elif board[i][j] == 'E':
                    board[i][j] = 'O'
                    
    def dfs(self, board, i, j):
        if 0 <= i < len(board) and 0 <= j < len(board[0]) and board[i][j] == 'O':
            board[i][j] = 'E'
            self.dfs(board, i-1, j)
            self.dfs(board, i+1, j)
            self.dfs(board, i, j-1)
            self.dfs(board, i, j+1)
        return
        