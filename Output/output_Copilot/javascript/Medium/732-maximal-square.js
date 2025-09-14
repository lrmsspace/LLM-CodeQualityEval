/**https://leetcode.com/problems/maximal-square/ */
//Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
// 
//Example 1:
//Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
//Output: 4
//Example 2:
//Input: matrix = [["0","1"],["1","0"]]
//Output: 1
//Example 3:
//Input: matrix = [["0"]]
//Output: 0
// 
//Constraints:
//	m == matrix.length
//	n == matrix[i].length
//	1 <= m, n <= 300
//	matrix[i][j] is '0' or '1'.
/**
 * @param {character[][]} matrix
 * @return {number}
 */
var maximalSquare = function(matrix) {
    if (matrix.length === 0 || matrix[0].length === 0) return 0;
    let max = 0;
    const dp = Array.from({ length: matrix.length }, () => Array(matrix[0].length).fill(0));
    for (let i = 0; i < matrix.length; i++) {
        for (let j = 0; j < matrix[0].length; j++) {
            if (matrix[i][j] === '1') {
                dp[i][j] = Math.min(dp[i - 1]?.[j - 1] || 0, dp[i - 1]?.[j] || 0, dp[i][j - 1] || 0) + 1;
                max = Math.max(max, dp[i][j]);
            }
        }
    }
    return max * max;    
};