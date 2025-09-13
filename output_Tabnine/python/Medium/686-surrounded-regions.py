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
        if not board or not board[0]:
            return
        
        rows, cols = len(board), len(board[0])
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        
        def dfs(row, col):
            if row < 0 or row >= rows or col < 0 or col >= cols or board[row][col]!= 'O':
                return
            
            board[row][col] = 'A'
            for dr, dc in directions:
                dfs(row + dr, col + dc)
        
        for i in range(rows):
            dfs(i, 0)
            dfs(i, cols - 1)
        
        for j in range(cols):
            dfs(0, j)
            dfs(rows - 1, j)
        
        for i in range(rows):
            for j in range(cols):
                if board[i][j] == 'A':
                    board[i][j] = 'O'
                elif board[i][j] == 'O':
                    board[i][j] = 'X'
        
        return board
        