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
    const count = { X: 0, O: 0 };
    for (const row of board) {
        for (const cell of row) {
            if (cell === 'X') count.X++;
            else if (cell === 'O') count.O++;
        }
    }

    if (count.X < count.O || count.X > count.O + 1) return false;

    const wins = [
        [0, 1, 2], [3, 4, 5], [6, 7, 8], // rows
        [0, 3, 6], [1, 4, 7], [2, 5, 8], // columns
        [0, 4, 8], [2, 4, 6] // diagonals
    ];

    let xWins = false;
    let oWins = false;

    for (const win of wins) {
        const [a, b, c] = win;
        if (board[Math.floor(a / 3)][a % 3] === 'X' &&
            board[Math.floor(b / 3)][b % 3] === 'X' &&
            board[Math.floor(c / 3)][c % 3] === 'X') {
            xWins = true;
        }
        if (board[Math.floor(a / 3)][a % 3] === 'O' &&
            board[Math.floor(b / 3)][b % 3] === 'O' &&
            board[Math.floor(c / 3)][c % 3] === 'O') {
            oWins = true;
        }
    }

    if (xWins && oWins) return false;
    if (xWins && count.X === count.O) return false;
    if (oWins && count.X > count.O) return false;

    return true;    
};