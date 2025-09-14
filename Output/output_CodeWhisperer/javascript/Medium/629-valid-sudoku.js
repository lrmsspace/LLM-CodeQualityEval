/**https://leetcode.com/problems/valid-sudoku/ */
//Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
//	Each row must contain the digits 1-9 without repetition.
//	Each column must contain the digits 1-9 without repetition.
//	Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
//Note:
//	A Sudoku board (partially filled) could be valid but is not necessarily solvable.
//	Only the filled cells need to be validated according to the mentioned rules.
// 
//Example 1:
//Input: board = 
//[["5","3",".",".","7",".",".",".","."]
//,["6",".",".","1","9","5",".",".","."]
//,[".","9","8",".",".",".",".","6","."]
//,["8",".",".",".","6",".",".",".","3"]
//,["4",".",".","8",".","3",".",".","1"]
//,["7",".",".",".","2",".",".",".","6"]
//,[".","6",".",".",".",".","2","8","."]
//,[".",".",".","4","1","9",".",".","5"]
//,[".",".",".",".","8",".",".","7","9"]]
//Output: true
//Example 2:
//Input: board = 
//[["8","3",".",".","7",".",".",".","."]
//,["6",".",".","1","9","5",".",".","."]
//,[".","9","8",".",".",".",".","6","."]
//,["8",".",".",".","6",".",".",".","3"]
//,["4",".",".","8",".","3",".",".","1"]
//,["7",".",".",".","2",".",".",".","6"]
//,[".","6",".",".",".",".","2","8","."]
//,[".",".",".","4","1","9",".",".","5"]
//,[".",".",".",".","8",".",".","7","9"]]
//Output: false
//Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
// 
//Constraints:
//	board.length == 9
//	board[i].length == 9
//	board[i][j] is a digit 1-9 or '.'.
/**
 * @param {character[][]} board
 * @return {boolean}
 */
var isValidSudoku = function(board) {
    let rows = new Array(9).fill(0).map(() => new Array(9).fill(0));
    let cols = new Array(9).fill(0).map(() => new Array(9).fill(0));
    let boxes = new Array(9).fill(0).map(() => new Array(9).fill(0));
    for (let i = 0; i < 9; i++) {
        for (let j = 0; j < 9; j++) {
            if (board[i][j] === '.') continue;
            let num = board[i][j] - '1';
            let box = Math.floor(i / 3) * 3 + Math.floor(j / 3);
            if (rows[i][num] || cols[j][num] || boxes[box][num]) return false;
            rows[i][num] = 1;
            cols[j][num] = 1;
            boxes[box][num] = 1;
        }
    }
    return true;
};