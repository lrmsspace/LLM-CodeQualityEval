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
    let rookRow = 0, rookCol = 0;
    let count = 0;
    for(let i = 0; i < board.length; i++){
        for(let j = 0; j < board[i].length; j++){
            if(board[i][j] === 'R'){
                rookRow = i;
                rookCol = j;
            }
        }
    }
    let row = rookRow, col = rookCol;
    while(row >= 0 && board[row][col] !== 'B'){
        if(board[row][col] === 'p'){
            count++;
            break;
        }
    }
    row = rookRow;
    col = rookCol;
    while(row < board.length && board[row][col] !== 'B'){
        if(board[row][col] === 'p'){
            count++;
            break;
        }
    }
    row = rookRow;
    col = rookCol;
    while(col >= 0 && board[row][col] !== 'B'){
        if(board[row][col] === 'p'){
            count++;
            break;
        }
    }
    row = rookRow;
    col = rookCol;
    while(col < board[row].length && board[row][col] !== 'B'){
        if(board[row][col] === 'p'){
            count++;
            break;
        }
    }
    return count;
};