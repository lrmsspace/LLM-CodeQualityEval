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
        def check_row(row):
            return board[row][0]!='' and board[row][0] == board[row][1] == board[row][2]
        
        def check_col(col):
            return board[0][col]!='' and board[0][col] == board[1][col] == board[2][col]
        
        def check_diag(diag):
            return board[0][0]!='' and board[0][0] == board[1][1] == board[2][2] if diag == 'diagonal1' else board[0][2]!= '' and board[0][2] == board[1][1] == board[2][0]
        
        for i in range(3):
            if check_row(i) or check_col(i) or check_diag('diagonal1') or check_diag('diagonal2'):
                return True
        
        return False
        