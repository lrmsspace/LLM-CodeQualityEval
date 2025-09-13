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
    let xCount = 0, oCount = 0, xWin = 0, oWin = 0;
    for(let i = 0; i < board.length; i++){
        for(let j = 0; j < board[i].length; j++){
            if(board[i][j] === 'X'){
                xCount++;
                if(i === j){
                    xWin++;
                }
                if(i + j === 2){
                    xWin++;
                }
                if(i === 1){
                    if(j === 0 || j === 2){
                        xWin++;
                    }
                }
            }
        }
    }
    for(let i = 0; i < board.length; i++){
        for(let j = 0; j < board[i].length; j++){
            if(board[i][j] === 'O'){
                oCount++;
                if(i === j){
                    oWin++;
                }
                if(i + j === 2){
                    oWin++;
                }
                if(i === 1){
                    if(j === 0 || j === 2){
                        oWin++;
                    }
                }
            }
        }
    }
    if(xCount - oCount !== 1 && xCount - oCount !== 0){
        return false;
    }
    if(xWin >= 3 || oWin >= 3){
        return false;
    }
    if(xWin === 3 && oWin === 0 && xCount === oCount){
        return false;
    }
    return true;
};