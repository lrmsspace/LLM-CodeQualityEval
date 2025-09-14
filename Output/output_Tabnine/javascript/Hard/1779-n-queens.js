/**https://leetcode.com/problems/n-queens/ */
//The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
//Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
//Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
// 
//Example 1:
//Input: n = 4
//Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
//Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
//Example 2:
//Input: n = 1
//Output: [["Q"]]
// 
//Constraints:
//	1 <= n <= 9
/**
 * @param {number} n
 * @return {string[][]}
 */
var solveNQueens = function(n) {
    let result = [];
    let cols = new Set(); // columns
    let diagonals1 = new Set(); // diagonals from top left to bottom right
    let diagonals2 = new Set(); // diagonals from top right to bottom left
    
    function backtrack(row) {
        if (row === n) {
            result.push(cols.map(col => '.' + 'Q'.repeat(col) + '.'));
            return;
        }
        
        for (let col = 0; col < n; col++) {
            if (cols.has(col) || diagonals1.has(row + col) || diagonals2.has(row - col)) continue;
            
            cols.add(col);
            diagonals1.add(row + col);
            diagonals2.add(row - col);
            
            backtrack(row + 1);
            
            cols.delete(col);
            diagonals1.delete(row + col);
            diagonals2.delete(row - col);
        }
    }
    
    backtrack(0);
    
    return result;
    
};