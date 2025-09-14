#https://leetcode.com/problems/check-if-move-is-legal/
#You are given a 0-indexed 8 x 8 grid board, where board[r][c] represents the cell (r, c) on a game board. On the board, free cells are represented by '.', white cells are represented by 'W', and black cells are represented by 'B'.
#Each move in this game consists of choosing a free cell and changing it to the color you are playing as (either white or black). However, a move is only legal if, after changing it, the cell becomes the endpoint of a good line (horizontal, vertical, or diagonal).
#A good line is a line of three or more cells (including the endpoints) where the endpoints of the line are one color, and the remaining cells in the middle are the opposite color (no cells in the line are free). You can find examples for good lines in the figure below:
#Given two integers rMove and cMove and a character color representing the color you are playing as (white or black), return true if changing cell (rMove, cMove) to color color is a legal move, or false if it is not legal.
# 
#Example 1:
#Input: board = [[".",".",".","B",".",".",".","."],[".",".",".","W",".",".",".","."],[".",".",".","W",".",".",".","."],[".",".",".","W",".",".",".","."],["W","B","B",".","W","W","W","B"],[".",".",".","B",".",".",".","."],[".",".",".","B",".",".",".","."],[".",".",".","W",".",".",".","."]], rMove = 4, cMove = 3, color = "B"
#Output: true
#Explanation: '.', 'W', and 'B' are represented by the colors blue, white, and black respectively, and cell (rMove, cMove) is marked with an 'X'.
#The two good lines with the chosen cell as an endpoint are annotated above with the red rectangles.
#Example 2:
#Input: board = [[".",".",".",".",".",".",".","."],[".","B",".",".","W",".",".","."],[".",".","W",".",".",".",".","."],[".",".",".","W","B",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".","B","W",".","."],[".",".",".",".",".",".","W","."],[".",".",".",".",".",".",".","B"]], rMove = 4, cMove = 4, color = "W"
#Output: false
#Explanation: While there are good lines with the chosen cell as a middle cell, there are no good lines with the chosen cell as an endpoint.
# 
#Constraints:
#	board.length == board[r].length == 8
#	0 <= rMove, cMove < 8
#	board[rMove][cMove] == '.'
#	color is either 'B' or 'W'.
class Solution(object):
    def checkMove(self, board, rMove, cMove, color):
        """
        :type board: List[List[str]]
        :type rMove: int
        :type cMove: int
        :type color: str
        :rtype: bool
        """
        def check_line(r, c, dr, dc):
            count = 0
            r1, c1 = r + dr, c + dc
            while 0 <= r1 < 8 and 0 <= c1 < 8 and board[r1][c1] != '.':
                if board[r1][c1] == color:
                    count += 1
                else:
                    break
                r1, c1 = r1 + dr, c1 + dc
            r1, c1 = r - dr, c - dc
            while 0 <= r1 < 8 and 0 <= c1 < 8 and board[r1][c1] != '.':
                if board[r1][c1] == color:
                    count += 1
                else:
                    break
                r1, c1 = r1 - dr, c1 - dc
            return count >= 2
        
        for dr in range(-1, 2):
            for dc in range(-1, 2):
                if dr == 0 and dc == 0:
                    continue
                if check_line(rMove, cMove, dr, dc):
                    return True
        return False
