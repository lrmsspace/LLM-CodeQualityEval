/**https://leetcode.com/problems/n-queens-ii/ */
//The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
//Given an integer n, return the number of distinct solutions to the n-queens puzzle.
// 
//Example 1:
//Input: n = 4
//Output: 2
//Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
//Example 2:
//Input: n = 1
//Output: 1
// 
//Constraints:
//	1 <= n <= 9
/**
 * @param {number} n
 * @return {number}
 */
var totalNQueens = function(n) {
    let count = 0;
    const board = Array.from({ length: n }, () => Array(n).fill('.'));
    const cols = new Set();
    const diag1 = new Set();
    const diag2 = new Set();

    const backtrack = (row) => {
        if (row === n) {
            count++;
            return;
        }
        for (let col = 0; col < n; col++) {
            if (cols.has(col) || diag1.has(row - col) || diag2.has(row + col)) continue;
            board[row][col] = 'Q';
            cols.add(col);
            diag1.add(row - col);
            diag2.add(row + col);
            backtrack(row + 1);
            board[row][col] = '.';
            cols.delete(col);
            diag1.delete(row - col);
            diag2.delete(row + col);
        }
    };

    backtrack(0);
    return count;    
};