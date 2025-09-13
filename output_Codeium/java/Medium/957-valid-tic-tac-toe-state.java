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
    public boolean validTicTacToe(String[] board) {
        int countX = 0, countO = 0;
        for (String s : board) {
            for (char c : s.toCharArray()) {
                if (c == 'X') countX++;
                if (c == 'O') countO++;
            }
        }
        if (countX < countO || countX - countO > 1) return false;
        if (countX < countO) return false;
        if (countX > countO && checkWin(board, 'X')) return false;
        if (countX == countO && checkWin(board, 'O')) return false;
        return true;
    }

    private boolean checkWin(String[] board, char c) {
        // Check rows and columns
        for (int i = 0; i < 3; i++) {
            if (board[i].charAt(0) == c && board[i].charAt(1) == c && board[i].charAt(2) == c) return true;
            if (board[0].charAt(i) == c && board[1].charAt(i) == c && board[2].charAt(i) == c) return true;
        }
        // Check diagonals
        if (board[0].charAt(0) == c && board[1].charAt(1) == c && board[2].charAt(2) == c) return true;
        if (board[0].charAt(2) == c && board[1].charAt(1) == c && board[2].charAt(0) == c) return true;
        return false;
    }   
}