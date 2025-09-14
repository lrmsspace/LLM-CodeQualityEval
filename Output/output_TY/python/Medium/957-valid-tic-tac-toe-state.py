#https://leetcode.com/problems/valid-tic-tac-toe-state/
#Given a Tic-Tac-Toe board as a string array board, return true if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game.
#The board is a 3 x 3 array that consists of characters ' ', 'X', and 'O'. The ' ' character represents an empty square.
#Here are the rules of Tic-Tac-Toe:
#	Players take turns placing characters into empty squares ' '.
#	The first player always places 'X' characters, while the second player always places 'O' characters.
#	'X' and 'O' characters are always placed into empty squares, never filled ones.
#	The game ends when there are three of the same (non-empty) character filling any row, column, or diagonal.
#	The game also ends if all squares are non-empty.
#	No more moves can be played if the game is over.
# 
#Example 1:
#Input: board = ["O  ","   ","   "]
#Output: false
#Explanation: The first player always plays "X".
#Example 2:
#Input: board = ["XOX"," X ","   "]
#Output: false
#Explanation: Players take turns making moves.
#Example 3:
#Input: board = ["XOX","O O","XOX"]
#Output: true
# 
#Constraints:
#	board.length == 3
#	board[i].length == 3
#	board[i][j] is either 'X', 'O', or ' '.
class Solution(object):
    def validTicTacToe(self, board):
        """
        :type board: List[str]
        :rtype: bool
        """
        x_count = 0
        o_count = 0
        for row in board:
            for ch in row:
                if ch == 'X':
                    x_count += 1
                elif ch == 'O':
                    o_count += 1
        if x_count - o_count not in [-1, 0]:
            return False
        for i in range(3):
            if board[i][0] == board[i][1] == board[i][2] != ' ':
                return board[i][0] == 'X' if x_count > o_count else board[i][0] == 'O'
            if board[0][i] == board[1][i] == board[2][i] != ' ':
                return board[0][i] == 'X' if x_count > o_count else board[0][i] == 'O'
        if board[0][0] == board[1][1] == board[2][2] != ' ':
            return board[0][0] == 'X' if x_count > o_count else board[0][0] == 'O'
        if board[0][2] == board[1][1] == board[2][0] != ' ':
            return board[0][2] == 'X' if x_count > o_count else board[0][2] == 'O'
        return True