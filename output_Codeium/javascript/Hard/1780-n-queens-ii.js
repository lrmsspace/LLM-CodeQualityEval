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
    let solutions = 0;
    const dfs = (row, cols) => {
        if (row === n) {
            solutions++;
            return;
        }
        for (let col = 0; col < n; col++) {
            if (cols.some((c, i) => c === col || c - i === col - row || c + i === col + row)) continue;
            dfs(row + 1, [...cols, col]);
        }
    };
    dfs(0, []);
    return solutions;

};