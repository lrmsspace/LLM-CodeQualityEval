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
    let row = new Array(9).fill(0).map(() => new Array(9).fill(0));
    let col = new Array(9).fill(0).map(() => new Array(9).fill(0));
    let box = new Array(9).fill(0).map(() => new Array(9).fill(0));
    for(let i = 0; i < 9; i++){
        for(let j = 0; j < 9; j++){
            if(board[i][j] !== '.'){
                let num = board[i][j] - '0' - 1;
                row[i][num]++;
                col[j][num]++;
            }
        }
    }
    for(let i = 0; i < 9; i++){
        for(let j = 0; j < 9; j++){
            if(board[i][j] !== '.'){
                let num = board[i][j] - '0' - 1;
                let boxNum = Math.floor(i / 3) * 3 + Math.floor(j / 3);
                if(row[i][num] > 1 || col[j][num] > 1 || box[boxNum][num] > 1){
                    return false;
                }
                box[boxNum][num]++;
            }
        }
    }
    return true;
};