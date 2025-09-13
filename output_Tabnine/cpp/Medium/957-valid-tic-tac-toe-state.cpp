/**https://leetcode.com/problems/valid-tic-tac-toe-state/ */
//Given a Tic-Tac-Toe board as a string array board, return true if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game.
//The board is a 3 x 3 array that consists of characters ' ', 'X', and 'O'. The ' ' character represents an empty square.
//Here are the rules of Tic-Tac-Toe:
//	Players take turns placing characters into empty squares ' '.
//	The first player always places 'X' characters, while the second player always places 'O' characters.
//	'X' and 'O' characters are always placed into empty squares, never filled ones.
//	The game ends when there are three of the same (non-empty) character filling any row, column, or diagonal.
//	The game also ends if all squares are non-empty.
//	No more moves can be played if the game is over.
// 
//Example 1:
//Input: board = ["O  ","   ","   "]
//Output: false
//Explanation: The first player always plays "X".
//Example 2:
//Input: board = ["XOX"," X ","   "]
//Output: false
//Explanation: Players take turns making moves.
//Example 3:
//Input: board = ["XOX","O O","XOX"]
//Output: true
// 
//Constraints:
//	board.length == 3
//	board[i].length == 3
//	board[i][j] is either 'X', 'O', or ' '.
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int rows = board.size();
        int cols = board[0].size();
        int xCount = 0, oCount = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'X')
                    xCount++;
                else if (board[i][j] == 'O')
                    oCount++;
            }
        }
        int xWinCount = 0, oWinCount = 0;
        for (int i = 0; i < rows; i++) {
            if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0]!= ' ') {
                (board[i][0] == 'X')? xWinCount++ : oWinCount++;
            }
        }
        for (int j = 0; j < cols; j++) {
            if (board[0][j] == board[1][j] && board[0][j] == board[2][j] && board[0][j]!= ' ') {
                (board[0][j] == 'X')? xWinCount++ : oWinCount++;
            }
        }
        if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0]!='') {
            (board[0][0] == 'X')? xWinCount++ : oWinCount++;
        }
        if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2]!='') {
            (board[0][2] == 'X')? xWinCount++ : oWinCount++;
        }
        if (xWinCount > 0 && xCount - xWinCount > 0)
        return false;
        
    }
};