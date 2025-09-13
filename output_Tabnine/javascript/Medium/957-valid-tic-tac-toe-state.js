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
    const rows = board.length;
    const cols = board[0].length;
    
    // Count X and O in rows
    const rowCounts = Array(rows).fill(0).map(() => Array(cols).fill(0));
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            if (board[i][j] === 'X') rowCounts[i][j]++;
            else if (board[i][j] === 'O') rowCounts[i][j]--;
        }
    }
    
    // Count X and O in columns
    const colCounts = Array(cols).fill(0).map(() => Array(rows).fill(0));
    for (let j = 0; j < cols; j++) {
        for (let i = 0; i < rows; i++) {
            if (board[i][j] === 'X') colCounts[j][i]++;
            else if (board[i][j] === 'O') colCounts[j][i]--;
        }
    }
    
    // Check diagonals
    const diagonalCounts = [0, 0];
    for (let i = 0; i < rows; i++) {
        if (board[i][i] === 'X') diagonalCounts[0]++;
        else if (board[i][i] === 'O') diagonalCounts[0]--;
        if (board[i][cols - 1 - i] === 'X') diagonalCounts[1]++;
        else if (board[i][cols - 1 - i] === 'O') diagonalCounts[1]--;
    }
    
    // Check if any player has won
    for (let i = 0; i < rows; i++) {
        if (rowCounts[i].every(count => count === 3) || colCounts[i].every(count => count === 3)) return true;
    }
    if (diagonalCounts.every(count => count === 3)) return true;
    
    return false;
    
};