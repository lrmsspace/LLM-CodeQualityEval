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
    const board = new Array(n).fill(0).map(() => new Array(n).fill(0));
    const cols = new Set();
    const diag1 = new Set();
    const diag2 = new Set();
    
    const backtrack = (row) => {
        if (row === n) {
            count++;
            return;
        }
        
        for (let col = 0; col < n; col++) {
            const d1 = row - col;
            const d2 = row + col;
            
            if (cols.has(col) || diag1.has(d1) || diag2.has(d2)) continue;
        }
    }
    
    backtrack(0);
    return count;
};