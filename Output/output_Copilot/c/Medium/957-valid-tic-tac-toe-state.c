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
bool validTicTacToe(char** board, int boardSize) {
    int i, j, x = 0, o = 0, xwin = 0, owin = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == 'X') {
                x++;
            } else if (board[i][j] == 'O') {
                o++;
            }
        }
    }
    if (x < o || x > o + 1) {
        return false;
    }
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == 'X') {
                xwin++;
            } else if (board[i][0] == 'O') {
                owin++;
            }
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if (board[0][i] == 'X') {
                xwin++;
            } else if (board[0][i] == 'O') {
                owin++;
            }
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'X') {
            xwin++;
        } else if (board[0][0] == 'O') {
            owin++;
        }
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == 'X') {
            xwin++;
        } else if (board[0][2] == 'O') {
            owin++;
        }
    }
    if (xwin && owin) {
        return false;
    }
    if (xwin && x == o) {
        return false;
    }
    if (owin && x > o) {
        return false;
    }
    return true;    
}