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
/**
 * @param {string[]} board
 * @return {boolean}
 */
var validTicTacToe = function(board) {
    let countX = 0;
    let countO = 0;
    for (let row of board) {
        for (let c of row) {
            if (c === 'X') {
                countX++;
            } else if (c === 'O') {
                countO++;
            }
        }
    }
    if (countX < countO || countX - countO > 1) return false;
    if (countX > countO && checkWin(board, 'X')) return false;
    if (countX === countO && checkWin(board, 'O')) return false;
    return true;
}

function checkWin(board, c) {
    for (let i = 0; i < 3; i++) {
        if (board[i][0] === c && board[i][1] === c && board[i][2] === c) return true;
        if (board[0][i] === c && board[1][i] === c && board[2][i] === c) return true;
    }
    if (board[0][0] === c && board[1][1] === c && board[2][2] === c) return true;
    if (board[0][2] === c && board[1][1] === c && board[2][0] === c) return true;
    return false;
};