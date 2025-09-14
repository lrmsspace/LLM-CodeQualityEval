/**https://leetcode.com/problems/available-captures-for-rook/ */
//You are given an 8 x 8 matrix representing a chessboard. There is exactly one white rook represented by 'R', some number of white bishops 'B', and some number of black pawns 'p'. Empty squares are represented by '.'.
//A rook can move any number of squares horizontally or vertically (up, down, left, right) until it reaches another piece or the edge of the board. A rook is attacking a pawn if it can move to the pawn's square in one move.
//Note: A rook cannot move through other pieces, such as bishops or pawns. This means a rook cannot attack a pawn if there is another piece blocking the path.
//Return the number of pawns the white rook is attacking.
// 
//Example 1:
//Input: board = [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","R",".",".",".","p"],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
//Output: 3
//Explanation:
//In this example, the rook is attacking all the pawns.
//Example 2:
//Input: board = [[".",".",".",".",".",".","."],[".","p","p","p","p","p",".","."],[".","p","p","B","p","p",".","."],[".","p","B","R","B","p",".","."],[".","p","p","B","p","p",".","."],[".","p","p","p","p","p",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
//Output: 0
//Explanation:
//The bishops are blocking the rook from attacking any of the pawns.
//Example 3:
//Input: board = [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","p",".",".",".","."],["p","p",".","R",".","p","B","."],[".",".",".",".",".",".",".","."],[".",".",".","B",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."]]
//Output: 3
//Explanation:
//The rook is attacking the pawns at positions b5, d6, and f5.
// 
//Constraints:
//	board.length == 8
//	board[i].length == 8
//	board[i][j] is either 'R', '.', 'B', or 'p'
//	There is exactly one cell with board[i][j] == 'R'
/**
 * @param {character[][]} board
 * @return {number}
 */
var numRookCaptures = function(board) {
    let rookPos = null;
    for (let i = 0; i < 8; i++) {
        for (let j = 0; j < 8; j++) {
            if (board[i][j] === 'R') {
                rookPos = {row: i, col: j};
                break;
            }
        }
    }
    
    let count = 0;
    
    // Check up
    for (let i = rookPos.row - 1; i >= 0; i--) {
        if (board[i][rookPos.col] === 'B') break;
        if (board[i][rookPos.col] === 'p') {
            count++;
            break;
        }
    }
    
    // Check down
    for (let i = rookPos.row + 1; i < 8; i++) {
        if (board[i][rookPos.col] === 'B') break;
        if (board[i][rookPos.col] === 'p') {
            count++;
            break;
        }
    }
    
    // Check left
    for (let j = rookPos.col - 1; j >= 0; j--) {
        if (board[rookPos.row][j] === 'B') break;
        if (board[rookPos.row][j] === 'p') {
            count++;
            break;
        }
    }
    
    // Check right
    for (let j = rookPos.col + 1; j < 8; j++) {
        if (board[rookPos.row][j] === 'B') break;
        if (board[rookPos.row][j] === 'p') {
            count++;
            break;
        }
    }
    
    return count;
    
};