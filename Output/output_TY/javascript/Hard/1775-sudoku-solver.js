/**https://leetcode.com/problems/sudoku-solver/ */
//Write a program to solve a Sudoku puzzle by filling the empty cells.
//A sudoku solution must satisfy all of the following rules:
//	Each of the digits 1-9 must occur exactly once in each row.
//	Each of the digits 1-9 must occur exactly once in each column.
//	Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
//The '.' character indicates empty cells.
// 
//Example 1:
//Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
//Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
//Explanation: The input board is shown above and the only valid solution is shown below:
// 
//Constraints:
//	board.length == 9
//	board[i].length == 9
//	board[i][j] is a digit or '.'.
//	It is guaranteed that the input board has only one solution.
/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var solveSudoku = function(board) {
    var row = new Array(9).fill(0).map(() => new Array(9).fill(0));
    var col = new Array(9).fill(0).map(() => new Array(9).fill(0));
    var block = new Array(9).fill(0).map(() => new Array(9).fill(0));
    var empty = [];
    for(var i = 0; i < 9; i++){
        for(var j = 0; j < 9; j++){
            if(board[i][j] != '.'){
                var num = board[i][j] - '0' - 1;
                row[i][num] = 1;
            }
        }
    }
    for(var i = 0; i < 9; i++){
        for(var j = 0; j < 9; j++){
            if(board[j][i] != '.'){
                var num = board[j][i] - '0' - 1;
                col[i][num] = 1;
            }
        }
    }
    for(var i = 0; i < 9; i++){
        for(var j = 0; j < 9; j++){
            if(board[Math.floor(i / 3) * 3 + Math.floor(j / 3)][i % 3 * 3 + j % 3] != '.'){
                var num = board[Math.floor(i / 3) * 3 + Math.floor(j / 3)][i % 3 * 3 + j % 3] - '0' - 1;
                block[i % 3 * 3 + j % 3][num] = 1;
            }
        }
    }
    for(var i = 0; i < 9; i++){
        for(var j = 0; j < 9; j++){
            if(board[i][j] == '.'){
                empty.push([i, j]);
            }
        }
    }
    var dfs = function(pos){
        if(pos == empty.length){
            return true;
        }
        var [i, j] = empty[pos];
        for(var k = 0; k < 9; k++){
            if(row[i][k] == 0 && col[j][k] == 0 && block[i % 3 * 3 + j % 3][k] == 0){
                board[i][j] = k + 1 + '0';
                row[i][k] = 1;
                col[j][k] = 1;
                block[i % 3 * 3 + j % 3][k]= 1;
            }
        }
    }
    for(var i = 0; i < empty.length; i++){
        dfs(i);
    }
    return board;
};